/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** manage the general use of the lib
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "dg_framebuffer.h"
#include "dg_window.h"

void *dg_init(dg_window_t *, void *);

void dg_end(void *, int);

int dg_loop(dg_window_t *, void *, sfTime);

static void dg_manage_event(dg_window_t *w)
{
    sfEvent event;

    w->events = (dg_event_t){0};
    while (sfRenderWindow_pollEvent(w->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w->window);
        w->events.mouse_pressed_left +=
            (event.type == sfEvtMouseButtonPressed &&
                event.mouseButton.button == sfMouseLeft) ? 1 : 0;
        w->events.mouse_pressed_right +=
            (event.type == sfEvtMouseButtonPressed &&
                event.mouseButton.button == sfMouseRight) ? 1 : 0;
    }
}

static int dg_render_screen(dg_window_t *window, void *var)
{
    sfClock *clock = sfClock_create();
    sfTime dt = {0};
    int to_return = 0;

    while (sfRenderWindow_isOpen(window->window)) {
        window->events = (dg_event_t){0};
        dg_manage_event(window);
        to_return = dg_loop(window, var, dt);
        dg_framebuffer_update(window->fb, window->window);
        sfRenderWindow_display(window->window);
        dt = sfClock_getElapsedTime(clock);
        sfClock_restart(clock);
        if (window->quit == true)
            sfRenderWindow_close(window->window);
    }
    dg_end(var, window->id);
    sfClock_destroy(clock);
    return to_return;
}

int dg_play(sfVector2u size, char *name, int id, void *import_data)
{
    dg_window_t *window = dg_window_create(size.x, size.y, name, id);
    void *data = 0;
    int to_return = 0;

    data = dg_init(window, import_data);
    sfRenderWindow_clear(window->window, sfBlack);
    to_return = dg_render_screen(window, data);
    dg_window_destroy(window);
    return to_return;
}
