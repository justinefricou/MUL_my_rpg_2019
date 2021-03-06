/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hud : options
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"
#include "hud/hud.h"

dg_entity_t *ent_hud_load(int *previous, dg_scene_t *scene)
{
    dg_entity_t *entity = dg_entity_create("hud_load");
    void *idata[3] = {entity, scene, previous};

    dg_entity_add_component(entity, cpt_script(&scp_hud_load_init,
        &scp_hud_load_loop, &scp_hud_load_end, idata));
    return entity;
}