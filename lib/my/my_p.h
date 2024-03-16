/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_hun
*/

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

#ifndef MY_P_H_
    #define MY_P_H_
typedef struct elem_s {
    sfRenderWindow *window;
    sfImage *im;
    int but;
    sfColor colo;
    int taille;
    char *file;
    char *name_save;
    int temp;
} elem_t;

elem_t verifshoot(elem_t elem);
int my_paint(int argc, char *str);
int use_window(elem_t elem);
void drawbutton(sfRenderWindow *window, sfImage *im);
void draw_all(sfRenderWindow *window);
void drawimage(sfRenderWindow *window, sfImage *im);
elem_t draw_colo(elem_t elem);
elem_t verifpos(elem_t elem);
elem_t draw_file(elem_t elem);
elem_t draw_trait(elem_t elem);
void draw_cli(elem_t elem, int x, int y);
void draw_pas(elem_t elem, int x, int y);
int help_paint(void);
void draw_pack(elem_t elem);

#endif /* !MY_P_H_ */
