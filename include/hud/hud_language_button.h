/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** epitech forbidden functions
*/

#ifndef HUD_LANGUAGE_BUTTON_H_
#define HUD_LANGUAGE_BUTTON_H_

#include "libdragon.h"
#include "ecs.h"
#include "hud.h"

//!\Do NOT INCLUDE SOMEWHERE ELSE THAN IN LANGUAGE BUTTONS FILES

typedef struct data {
    sfVector2f *pos;
    sfColor *color;
    int active;
    sfText *text;
    sfVector2f *tpos;
    dg_entity_t *text_ent;
    sfMusic *sound_active;
} data_t;

#endif /*HUD_KEYMAP_BUTTON_H_*/
