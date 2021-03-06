/*
** EPITECH PROJECT, 2020
** scene_menu
** File description:
** scene_menu
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "game_scenes.h"
#include "button_action.h"
#include "fight_scenes.h"
#include "init_general_data_for_new_game.h"

void new_game(int *previous, void *data, dg_window_t *w)
{
    general_data_t *general_data = w->general_data;

    init_general_data_for_new_game(general_data);
    create_game_scenes(w->general_data, "island");
    sfMusic_stop(dg_ressources_get_audio_by_name("menu_theme"));
    sfMusic_play(dg_ressources_get_audio_by_name("game_theme"));
    dg_scene_manager_remove("main_menu");
    dg_scene_manager_remove("main_menu_hover");
}

void load_game(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("main_menu_hover");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_load(previous, scene));
}

void how_to_play(int *previous, void *data, dg_window_t *w)
{
    dg_scene_t *scene = dg_scene_manager_get_scene("main_menu_hover");

    *previous = 0;
    dg_scene_add_ent(scene, ent_hud_htp(previous, scene));
}