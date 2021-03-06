/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Saves player's infos : name, position, level and XPs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include "libmy.h"
#include "save_load.h"

void save_player_name(char *name, FILE *save_file)
{
    write_str_in_save_file("player_name ", save_file);
    write_str_in_save_file(name, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

void save_player_position(sfVector2f *position, FILE *save_file)
{
    if (!position)
        return;
    write_str_in_save_file("player_position ", save_file);
    write_int_in_save_file(position->x, save_file);
    fwrite(",", sizeof(char), 1, save_file);
    write_int_in_save_file(position->y, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}

void save_player_lvl_and_xp(player_t player, FILE *save_file)
{
    write_str_in_save_file("player_level ", save_file);
    write_int_in_save_file(player.level, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    write_str_in_save_file("player_xp ", save_file);
    write_int_in_save_file(player.xp.x, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
    write_str_in_save_file("player_max_xp ", save_file);
    write_int_in_save_file(player.xp.y, save_file);
    fwrite("\n", sizeof(char), 1, save_file);
}