/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_putchar
*/

#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}
