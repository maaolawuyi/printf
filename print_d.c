#include "main.h"

/**
 * print_d - print integers.
 * @my_list: argument.
 * Return: count of chars.
 */

int print_d(va_list my_list)
{
	int decimal = 1;
	int num_chara_print = 0;
	long int digit = va_arg(my_list, int);
	long int digitaux;

	if (digit < 0)
	{
		num_chara_print += _putchar('-');
		digit *= -1;
	}

	if (digit < 10)
		return (num_chara_print += _putchar(digit + '0'));

	digitaux = digit;

	while (digitaux > 9)
	{
		decimal *= 10;
		digitaux /= 10;
	}
	while (decimal >= 1)
	{
		num_chara_print += _putchar(((digit / decimal) % 10) + '0');
		decimal /= 10;
	}

	return (num_chara_print);
}
