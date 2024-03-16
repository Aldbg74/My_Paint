/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** verifpos
*/

#include "include/my.h"
#include "include/my_p.h"

static void verifpos_pas_aux(elem_t elem, int x, int y)
{
    if (x >= 80 && y >= 45 && x <= 110 && y <= 75) {
        draw_pas(elem, 80, 45);
    }
    if (x >= 10 && y >= 80 && x <= 40 && y <= 110) {
        draw_pas(elem, 10, 80);
    }
    if (x >= 45 && y >= 80 && x <= 75 && y <= 110) {
        draw_pas(elem, 45, 80);
    }
    if (x >= 80 && y >= 80 && x <= 110 && y <= 110) {
        draw_pas(elem, 80, 80);
    }
    if (x >= 115 && y >= 45 && x <= 145 && y <= 75) {
        draw_pas(elem, 115, 45);
    }
    if (x >= 45 && y >= 45 && x <= 75 && y <= 75) {
        draw_pas(elem, 45, 45);
    }
}

void verifpos_pas(elem_t elem, int x, int y)
{
    sfRenderWindow_clear(elem.window, sfWhite);
    if (x >= 10 && y >= 45 && x <= 40 && y <= 75) {
        draw_pas(elem, 10, 45);
    }
    verifpos_pas_aux(elem, x, y);
    draw_pack(elem);
    sfRenderWindow_display(elem.window);
}

static elem_t verifpos_aux2(elem_t elem, int x, int y)
{
    if (x >= 80 && y >= 80 && x <= 110 && y <= 110
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 80, 80);
        elem.colo = sfBlack;
        elem.temp = 1;
    }
    if (x >= 115 && y >= 45 && x <= 145 && y <= 75
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 115, 45);
        elem.colo = sfCyan;
        elem.temp = 1;
    }
    if (x >= 45 && y >= 45 && x <= 75 && y <= 75
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 45, 45);
        elem.colo = sfGreen;
        elem.temp = 1;
    }
    return elem;
}

static elem_t verifpos_aux(elem_t elem, int x, int y)
{
    if (x >= 80 && y >= 45 && x <= 110 && y <= 75
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 80, 45);
        elem.colo = sfBlue;
        elem.temp = 1;
    }
    if (x >= 10 && y >= 80 && x <= 40 && y <= 110
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 10, 80);
        elem.colo = sfMagenta;
        elem.temp = 1;
    }
    if (x >= 45 && y >= 80 && x <= 75 && y <= 110
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 45, 80);
        elem.colo = sfYellow;
        elem.temp = 1;
    }
    elem = verifpos_aux2(elem, x, y);
    return elem;
}

elem_t verifpos(elem_t elem)
{
    sfVector2i mouse;
    int x;
    int y;

    elem.temp = 0;
    while (elem.temp == 0) {
        mouse = sfMouse_getPositionRenderWindow(elem.window);
        x = mouse.x;
        y = mouse.y;
        if (x >= 10 && y >= 45 && x <= 40 && y <= 75
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            draw_cli(elem, 10, 45);
            elem.colo = sfRed;
            elem.temp = 1;
        }
        elem = verifpos_aux(elem, x, y);
    }
    return elem;
}
