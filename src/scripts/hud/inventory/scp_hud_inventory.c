/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud_inventory.h"

void *scp_hud_inventory_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));
    dg_scene_t *scene = idata[1];
    dg_entity_t *entity = idata[0];
    dg_component_t *pos = dg_cpt_pos(350, 20);
    dg_component_t *selector = cpt_shape_rectangle((sfVector2f){350, 20},
        (sfVector2f){0, 0}, (sfColor){255, 255, 255, 100},
        (sfColor){0, 0, 0, 0});

    dg_entity_add_component(entity, pos);
    dg_entity_add_component(entity, selector);
    data->previous = idata[2];
    data->selector = selector->data;
    data->hud_box = ent_hud_box(350, 20, 32, 20);
    dg_scene_add_ent(scene, data->hud_box);
    inventory_set_sounds(data);
    return data;
}

/*void hud_menu_active(dg_window_t *w, data_t *data)
{
    if (w->events.keyboard_pressed_down && data->select < data->llen - 1) {
        sound_play(data->sound_move);
        data->select++;
    }
    if (w->events.keyboard_pressed_up && data->select > 0) {
        sound_play(data->sound_move);
        data->select--;
    }
    if (w->events.keyboard_pressed_enter || w->events.keyboard_pressed_space) {
        sound_play(data->sound_activate);
        data->button_list[data->select].action
            (&(data->is_active), data->button_list[data->select].data, w);
    }
}*/

void scp_hud_inventory_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    //sfRectangleShape_setPosition(data->selector,
    //    (sfVector2f){2 * 3, 2 + data->select * (16 * 3)});
    //if (data->is_active)
    //    hud_menu_active(w, data);
    //update_position(data);
    if (keymap_is_clicked(w, "cancel", 1)) {
        sound_play(data->sound_activate);
        *(data->previous) = 1;
        data->hud_box->destroy = 1;
        entity->destroy = 1;
    }
}

void scp_hud_inventory_end(void *data)
{
    data_t *d = (data_t *)data;

    //free(d->button_list);
    //free(d->buttons);
    free(d);
}