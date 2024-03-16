/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** color
*/
#include "include/my.h"
#include "include/my_p.h"

static void drawtaille4(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/taille_4.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {115, 115};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void drawtaille3(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/taille_3.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {80, 115};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void drawtaille2(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/taille_2.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {45, 115};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void drawtaille1(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/taille_1.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {10, 115};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

void verifcli_pas(elem_t elem, int x, int y)
{
    sfRenderWindow_clear(elem.window, sfWhite);
    if (x >= 10 && y >= 115 && x <= 40 && y <= 145) {
        draw_pas(elem, 10, 115);
    }
    if (x >= 45 && y >= 115 && x <= 75 && y <= 145) {
        draw_pas(elem, 45, 115);
    }
    if (x >= 80 && y >= 115 && x <= 110 && y <= 145) {
        draw_cli(elem, 80, 115);
    }
    if (x >= 115 && y >= 115 && x <= 145 && y <= 145) {
        draw_cli(elem, 115, 115);
    }
    drawtaille1(elem.window);
    drawtaille2(elem.window);
    drawtaille3(elem.window);
    drawtaille4(elem.window);
    sfRenderWindow_display(elem.window);
}

static elem_t verifcli_aux(elem_t elem, int x, int y)
{
    if (x >= 45 && y >= 115 && x <= 75 && y <= 145
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 45, 115);
        elem.taille = 8;
        elem.temp = 1;
    }
    if (x >= 80 && y >= 115 && x <= 110 && y <= 145
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 80, 115);
        elem.taille = 12;
        elem.temp = 1;
    }
    if (x >= 115 && y >= 115 && x <= 145 && y <= 145
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 115, 115);
        elem.taille = 16;
        elem.temp = 1;
    }
    return elem;
}

elem_t verifcli(elem_t elem)
{
    sfVector2i mouse;
    int x;
    int y;

    elem.temp = 0;
    while (elem.temp == 0) {
        mouse = sfMouse_getPositionRenderWindow(elem.window);
        x = mouse.x;
        y = mouse.y;
        if (x >= 10 && y >= 115 && x <= 40 && y <= 145
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            draw_cli(elem, 10, 115);
            elem.taille = 4;
            elem.temp = 1;
        }
        elem = verifcli_aux(elem, x, y);
    }
    return elem;
}

elem_t draw_trait(elem_t elem)
{
    sfRenderWindow_clear(elem.window, sfWhite);
    drawimage(elem.window, elem.im);
    draw_all(elem.window);
    drawtaille1(elem.window);
    drawtaille2(elem.window);
    drawtaille3(elem.window);
    drawtaille4(elem.window);
    sfRenderWindow_display(elem.window);
    elem = verifcli(elem);
    return elem;
}
