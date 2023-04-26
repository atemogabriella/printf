#include "main.h"
/**
 *print_int - print an integer from the variadic function
 * @arg: variadic parameter
 *
 * Return: number of characters printed on success
*/
int print_int(va_list arg)
{
	int i = 0;
	int count;
	int num;
	int arr[11];
	char x[1];

	num = va_arg(arg, int);
	while (num != 0)
	{
		arr[i] = (num % 10);
		num = num / 10;
		if (num == 0)
			break;
		i++;
	}

	for (i ; i >= 0 ; 1--)
	{
		x[1] = ('0' + arr[i]);
		count += write(1, x, 1);
	}
	return (count);
}
