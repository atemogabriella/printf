#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
void print_string(va_list args, int *count);
void print_char(va_list args, int *count);
void print_int(va_list args, int *count);
#endif
