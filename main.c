/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_hunter
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

int help_paint(void)
{
    my_putstr("To launch the program you must call my_paint the optional");
    my_putstr(" arguments that you can put afterwards are, the save name ");
    my_putstr("of the file with its type if this is not specified the image");
    my_putstr(" will be called my_image.jpg the second parameter is the ");
    my_putstr("name of an image that you would like to open. The first ");
    my_putstr("button allows you to choose the pencil as well as the color ");
    my_putstr("and then the writing size.\nThe second button allows you to ");
    my_putstr("choose the eraser and its size.\nThe third button allows you");
    my_putstr(" to save the image, reset it, and open another image.\n");
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        my_paint(argc, "my_image.jpg");
        return 1;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        help_paint();
        return 1;
    }
    my_paint(argc, argv[1]);
    return 1;
}
