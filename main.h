#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(char c, int *char_print);
int print_string(char *str, int *char_print);
int print_integer(int num, int *char_print);
int print_binary(unsigned int num, int *char_print);
#endif
