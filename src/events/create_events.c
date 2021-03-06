/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** background_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "general_data.h"
#include "instructions.h"

static const key_setter_t key_setter[14] = {
    NULL, &ins_set_set, &ins_set_if, &ins_set_while, &ins_set_for,
    &ins_set_end, &ins_set_give, &ins_set_take, &ins_set_tp, &ins_set_dialog,
    &ins_set_talk, &ins_set_answer, &ins_set_battle, &ins_set_move};

instruction_t *add_instruction(instruction_t *old,
    int len, instruction_t data)
{
    instruction_t *new = malloc(sizeof(instruction_t) * (len + 2));

    for (int i = 0; i < len; i++)
        new[i] = old[i];
    new[len] = data;
    new[len + 1].keycode = NONE;
    new[len + 1].len = 0;
    new[len + 1].parameters = NULL;
    free(old);
    return new;
}

static instruction_t *set_instructions(instruction_t *tmp,
    general_data_t *gd, int *len)
{
    instruction_t *instructions = malloc(sizeof(instruction_t));
    instruction_t to_add = {0};

    for (int i = 0; tmp[i].keycode != NONE; i++) {
        to_add.keycode = tmp[i].keycode;
        if (key_setter[tmp[i].keycode]) {
            to_add.parameters = key_setter[tmp[i].keycode](tmp, &i,
                gd, &(to_add.len));
        } else {
            to_add.parameters = NULL;
        }
        instructions = add_instruction(instructions, *len, to_add);
        *len += 1;
    }
    return instructions;
}

static event_t *interpret_events(event_t *tmp_event, general_data_t *gd)
{
    event_t *event = 0;
    int len = 0;

    for (len = 0; tmp_event[len].parameters; len++);
    gd->event_manager.event_len = len;
    gd->event_manager.var_len = 0;
    gd->event_manager.var = NULL;
    event = malloc(sizeof(event_t) * (len + 1));
    for (int i = 0; i < len; i++) {
        event[i].name = tmp_event[i].name;
        event[i].len = 0;
        event[i].parameters =
        set_instructions(tmp_event[i].parameters, gd, &(event[i].len));
    }
    event[len].parameters = NULL;
    return event;
}

void create_events(general_data_t *gd)
{
    event_t *tmp_event = set_text_events();

    gd->event_manager.events = interpret_events(tmp_event, gd);
    variable_to_int("PV", gd);
    variable_to_int("PM", gd);
    variable_to_int("PV_MAX", gd);
    variable_to_int("PM_MAX", gd);
    variable_to_int("MONEY", gd);
    variable_to_int("XP", gd);
    variable_to_int("LEVEL", gd);
    variable_to_int("WEIGHT", gd);
    variable_to_int("WEIGHT_MAX", gd);
    variable_to_int("BATTLE", gd);
}