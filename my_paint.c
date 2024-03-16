/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** cwindow
*/

#include "include/my.h"
#include "include/my_p.h"
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

static void draw_aux(sfVector2i mouse, elem_t elem)
{
    int px = mouse.x;
    int py = mouse.y;

    for (int x = 0; x < (elem.taille / 2); x++) {
        for (int y = 0; y < (elem.taille / 2); y++) {
            sfImage_setPixel(elem.im, (px + x), (py - y), elem.colo);
        }
    }
    for (int x = 0; x < (elem.taille / 2); x++) {
        for (int y = 0; y < (elem.taille / 2); y++) {
            sfImage_setPixel(elem.im, (px - x), (py - y), elem.colo);
        }
    }
}

void draw(sfVector2i mouse, elem_t elem)
{
    int px = mouse.x;
    int py = mouse.y;

    for (int x = 0; x < (elem.taille / 2); x++) {
        for (int y = 0; y < (elem.taille / 2); y++) {
            sfImage_setPixel(elem.im, (px + x), (py + y), elem.colo);
        }
    }
    for (int x = 0; x < (elem.taille / 2); x++) {
        for (int y = 0; y < (elem.taille / 2); y++) {
            sfImage_setPixel(elem.im, (px - x), (py + y), elem.colo);
        }
    }
    draw_aux(mouse, elem);
}

elem_t modif_mod(int x, int y, elem_t elem)
{
    if (x >= 10 && y >= 0 && x <= 40 && y <= 30
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 10, 0);
        elem = draw_colo(elem);
        elem = draw_trait(elem);
    }
    if (x >= 45 && y >= 0 && x <= 75 && y <= 30
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        elem.colo = sfWhite;
        draw_cli(elem, 45, 0);
        elem = draw_trait(elem);
    }
    if (x >= 80 && y >= 0 && x <= 110 && y <= 30
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 80, 0);
        elem = draw_file(elem);
    }
    return elem;
}

void passage(sfVector2i mouse, elem_t elem)
{
    int x = mouse.x;
    int y = mouse.y;

    if (x >= 10 && y >= 0 && x <= 40 && y <= 30) {
        draw_pas(elem, 10, 0);
    }
    if (x >= 45 && y >= 0 && x <= 75 && y <= 30) {
        draw_pas(elem, 45, 0);
    }
    if (x >= 80 && y >= 0 && x <= 110 && y <= 30) {
        draw_pas(elem, 80, 0);
    }
}

static int test_erreur(elem_t elem, sfVector2i mouse)
{
    if (mouse.x >= (1920 - (elem.taille / 2))
    || mouse.y >= (1080 - (elem.taille / 2))
    || mouse.x <= (0 + (elem.taille / 2))
    || mouse.y <= (0 + (elem.taille / 2))) {
        return 0;
    } else {
        return 1;
    }
}

elem_t verifshoot(elem_t elem)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(elem.window);

    if (test_erreur(elem, mouse) == 0)
        return elem;
    passage(mouse, elem);
    elem = modif_mod(mouse.x, mouse.y, elem);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfRenderWindow_clear(elem.window, sfWhite);
        draw(mouse, elem);
        drawimage(elem.window, elem.im);
        draw_all(elem.window);
        sfRenderWindow_display(elem.window);
    }
    return elem;
}

int my_paint(int argc, char *str)
{
    elem_t elem;

    elem.name_save = str;
    elem.file = NULL;
    elem.but = 0;
    elem.colo = sfBlack;
    elem.taille = 15;
    elem.temp = 0;
    use_window(elem);
    return 0;
}
