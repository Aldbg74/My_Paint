/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** for_fich
*/

#include "include/my.h"
#include "include/my_p.h"

static void open_file(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/o_file.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {80, 45};
    sfVector2f taille = {0.06, 0.06};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void new_file(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/n_file.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {45, 45};
    sfVector2f taille = {0.07, 0.07};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

static void save_file(sfRenderWindow *window)
{
    sfTexture *but = sfTexture_createFromFile("button/s_file.png", NULL);
    sfSprite* button = sfSprite_create();
    sfVector2f pos = {10, 45};
    sfVector2f taille = {0.1, 0.1};

    sfSprite_setPosition(button, pos);
    sfSprite_setScale(button, taille);
    sfSprite_setTexture(button, but, sfFalse);
    sfRenderWindow_drawSprite(window, button, NULL);
}

elem_t veriffile_pas(elem_t elem, int x, int y)
{
    sfRenderWindow_clear(elem.window, sfWhite);
    if (x >= 10 && y >= 45 && x <= 40 && y <= 75) {
        draw_pas(elem, 10, 45);
    }
    if (x >= 45 && y >= 45 && x <= 75 && y <= 75) {
        draw_pas(elem, 45, 45);
    }
    if (x >= 80 && y >= 45 && x <= 110 && y <= 75) {
        draw_pas(elem, 80, 45);
    }
    save_file(elem.window);
    new_file(elem.window);
    open_file(elem.window);
    sfRenderWindow_display(elem.window);
}

elem_t veriffile_aux(elem_t elem, int x, int y)
{
    if (x >= 45 && y >= 45 && x <= 75 && y <= 75
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 45, 45);
        elem.im = sfImage_createFromColor(1920, 1080, sfWhite);
        elem.temp = 1;
    }
    if (x >= 80 && y >= 45 && x <= 110 && y <= 75
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_cli(elem, 80, 45);
        if (elem.file == NULL)
            return elem;
        elem.im = sfImage_createFromFile(elem.file);
        elem.temp = 1;
    }
    return elem;
}

elem_t veriffile(elem_t elem)
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
            sfImage_saveToFile(elem.im, elem.name_save);
            elem.temp = 1;
        }
        elem = veriffile_aux(elem, x, y);
    }
    return elem;
}

elem_t draw_file(elem_t elem)
{
    sfRenderWindow_clear(elem.window, sfWhite);
    drawimage(elem.window, elem.im);
    draw_all(elem.window);
    save_file(elem.window);
    new_file(elem.window);
    open_file(elem.window);
    sfRenderWindow_display(elem.window);
    elem = veriffile(elem);
    return elem;
}
