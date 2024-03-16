/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** window
*/

#include "include/my.h"
#include "include/my_p.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

static void drawbutton6(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/file.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {80, 0};
    sfVector2f taille = {0.14, 0.14};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void drawbutton2(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/del.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {45, 0};
    sfVector2f taille = {0.08, 0.08};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void drawbutton1(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/write.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {10, 0};
    sfVector2f taille = {0.08, 0.08};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

void drawimage(sfRenderWindow *window, sfImage *im)
{
    sfTexture *but = sfTexture_createFromImage(im, NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {0, 0};
    sfVector2f taille = {1, 1};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static elem_t cwindow(elem_t elem)
{
    sfVideoMode mode = {1920, 1080, 32};

    elem.window = sfRenderWindow_create(mode, "my paint", sfResize
    | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(elem.window, 120);
    return elem;
}

void draw_all(sfRenderWindow *window)
{
    drawbutton1(window);
    drawbutton2(window);
    drawbutton6(window);
}

int verif_end(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return 0;
        }
    }
    return 1;
}

int use_window(elem_t elem)
{
    sfEvent event;

    elem = cwindow(elem);
    elem.im = sfImage_createFromColor(1920, 1080, sfWhite);
    sfRenderWindow_clear(elem.window, sfWhite);
    drawimage(elem.window, elem.im);
    draw_all(elem.window);
    sfRenderWindow_display(elem.window);
    while (sfRenderWindow_isOpen(elem.window)
    && sfRenderWindow_hasFocus(elem.window)) {
        if (verif_end(elem.window, event) == 0)
            return 0;
        elem = verifshoot(elem);
    }
    sfRenderWindow_destroy(elem.window);
    return 0;
}
