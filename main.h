#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.>
#include <unistd.h>

int _printf(const char *format, ...);
int binary(int num);
int octal(int num);
int print_c(va_list my_list);
int print_s(va_list my_list);
int print_d(va_list my_list);
int print_%(va_list my_list);
int print_rev_s(va_list my_list);

#endif
