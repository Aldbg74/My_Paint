/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** draw_inter
*/

#include "include/my.h"
#include "include/my_p.h"

void draw_pas(elem_t elem, int x, int y)
{
    sfRectangleShape* button = sfRectangleShape_create();
    sfVector2f pos = {x, y};
    sfVector2f taille = {35, 30};
    sfColor colo = sfColor_fromRGBA(255, 255, 255, 100);

    sfRenderWindow_clear(elem.window, sfWhite);
    drawimage(elem.window, elem.im);
    draw_all(elem.window);
    sfRectangleShape_setSize(button, taille);
    sfRectangleShape_setFillColor(button, colo);
    sfRectangleShape_setPosition(button, pos);
    sfRenderWindow_drawRectangleShape(elem.window, button, NULL);
    sfRenderWindow_display(elem.window);
}

void draw_cli(elem_t elem, int x, int y)
{
    sfRectangleShape* button = sfRectangleShape_create();
    sfVector2f pos = {x, y};
    sfVector2f taille = {35, 30};
    sfColor colo = sfColor_fromRGBA(216, 250, 8, 200);

    sfRenderWindow_clear(elem.window, sfWhite);
    drawimage(elem.window, elem.im);
    draw_all(elem.window);
    sfRectangleShape_setSize(button, taille);
    sfRectangleShape_setFillColor(button, colo);
    sfRectangleShape_setPosition(button, pos);
    sfRenderWindow_drawRectangleShape(elem.window, button, NULL);
    sfRenderWindow_display(elem.window);
}
