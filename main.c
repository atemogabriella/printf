#include <stdio.h>
#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("%d, %d", len, len2);
    len = _printf("string: %s", "Let's try to printf a simple sentence.\n");
    len2 = printf("string: %s", "Let's try to printf a simple sentence.\n");
    printf("%d, %d", len, len2);
    len = _printf("Null: %s", NULL);
    printf("%d", len);
    len = _printf("%K");
    printf("K: %d", len);
    return (0);
}
