/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** enti
*/

#include "my.h"

char *entier_convert(int x)
{
    char *rep = malloc(sizeof(char *));
    int y;
    int z = 0;

    while (x > 0) {
        y = x % 10;
        rep[z] = (y + 48);
        x = x / 10;
        z++;
    }
    return (my_revstr(rep));
}
