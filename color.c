/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** color
*/
#include "include/my.h"
#include "include/my_p.h"

void drawcolo7(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/colo_7.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {80, 80};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

void drawcolo6(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/colo_6.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {45, 80};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

void drawcolo5(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/colo_5.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {10, 80};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void drawcolo4(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/colo_4.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {115, 45};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void drawcolo3(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/colo_3.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {80, 45};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void drawcolo2(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/colo_2.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {45, 45};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void drawcolo1(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/colo_1.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {10, 45};
    sfVector2f taille = {0.8, 0.8};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

void draw_pack(elem_t elem)
{
    drawcolo1(elem.window);
    drawcolo2(elem.window);
    drawcolo3(elem.window);
    drawcolo4(elem.window);
    drawcolo5(elem.window);
    drawcolo6(elem.window);
    drawcolo7(elem.window);
}

elem_t draw_colo(elem_t elem)
{
    sfRenderWindow_clear(elem.window, sfWhite);
    drawimage(elem.window, elem.im);
    draw_all(elem.window);
    draw_pack(elem);
    sfRenderWindow_display(elem.window);
    elem = verifpos(elem);
    return elem;
}
