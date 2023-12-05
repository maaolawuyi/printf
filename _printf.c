#include "main.h"

/**
 * _printf - Emulate the original.
 * @format: Format by specifier.
 * Return: count of chars.
 */

int _printf(const char *format, ...)
{
	int num_chara_print = 0;
	va_list my_list;

	if (format == NULL)
		return (-1);

	va_start(my_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			num_chara_print++;
		}
		else
		{
			format++;
			if (format == '\0')
			{
				break;
			}

			if (format == '%')
			{
				write(1, format, 1);
				num_chara_print++;
			}
			else if (format == 'c')
			{
				char c = va_arg(my_list, int);
				write(1, &c, 1);
				num_chara_print++;
			}
			else if (format == 's')
			{
				char *str = va_arg(my_list, char*);
				int i = 0;

				while (str[i] != ''\0)
					i++;

				write(i, str, i);
				num_chra_print += i;
			}
		}

		format++;
	}

	va_end(my_list);

	return (num_chara_print);
}


