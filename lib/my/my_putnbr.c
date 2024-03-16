/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday03-killian.quintin
** File description:
** displays the number given as a parameter
** my_putnbr
*/

#include "my.h"

int my_putnbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    if (nb == 2147483647) {
        write(1, "2147483647", 10);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb < 10)
        my_putchar(nb + 48);
    else {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    return 0;
}
