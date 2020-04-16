/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** scene middle layer
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"

dg_scene_t *scene_game_middle(void)
{
    dg_scene_t *scene = dg_scene_create("layer_middle");

    dg_scene_add_ent(scene, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene, dg_system_create(&sys_render, 1));
    dg_scene_add_sys(scene, dg_system_create(&sys_tm_render, 1));
    return scene;
}