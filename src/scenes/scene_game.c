/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** scene_endless_waves
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "general_data.h"

static void scene_add_ent(dg_scene_t *scene)
{
    dg_entity_t *camera = dg_ent_camera(0, 0);

    dg_scene_add_ent(scene, camera);
    dg_scene_add_ent(scene, ent_music("./sound/theme_game.ogg"));
    dg_scene_add_ent(scene, ent_map(3, 1, 0, 0));
    dg_scene_add_ent(scene, entity_player_create());
}

static void scene_add_sys(dg_scene_t *scene)
{
    dg_scene_add_sys(scene, dg_system_create(&sys_script, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_display_text, 1));
    dg_scene_add_sys(scene, dg_system_create(&dg_sys_animator, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_escape, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_player_control, 0));
}

dg_scene_t *scene_game(void)
{
    dg_scene_t *scene = dg_scene_create("game");

    scene_add_ent(scene);
    scene_add_sys(scene);
    scene->display = 1;
    scene->run = 1;
    return scene;
}