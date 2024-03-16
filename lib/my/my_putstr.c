/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}
