#include "main.h"

/**
 * _printf - Emulate the original.
 * @format: Format by specifier.
 * Return: count of chars.
 */

int _printf(const char *format, ...)
{
	int i, ptd = 0, num_char_print = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list my_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(my_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			num_char_print++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, my_list);
			precision = get_precision(format, &i, my_list);
			size = get_size(format, &i);
			++i;
			ptd = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (ptd == -1)
				return (-1);
			num_char_print += printed;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(my_list);

	return (num_char_print);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char.
 */

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}

