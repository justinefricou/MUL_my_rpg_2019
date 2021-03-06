/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Loads a game.
*/

#include <stdio.h>
#include <unistd.h>
#include "save_load.h"

static int load_saved_data(general_data_t *data, FILE *save_file)
{
    load_saved_player_name(data, save_file);
    load_saved_player_lvl(&(data->player), save_file);
    load_saved_player_xp(&(data->player), save_file);
    load_saved_player_pv(data, save_file);
    load_saved_player_pm(data, save_file);
    load_saved_player_money(&(data->player), save_file);
    load_saved_inventory(&(data->inventory), save_file);
    load_saved_clues(&(data->clues), save_file);
    load_saved_event_vars(&(data->event_manager), save_file);
    return (0);
}

int load_saved_game(general_data_t *data, int save_nb)
{
    FILE *save_file = NULL;
    int return_value = 0;

    return_value = open_save_file(&save_file, save_nb, "r");
    if (return_value != 84) {
        return_value = load_saved_data(data, save_file);
        fclose(save_file);
    }
    return (return_value);
}