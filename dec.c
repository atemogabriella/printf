include "main.h"
/**
 *print_int - print an integer to base 10
 * @args: variadic parameter
 * 
 * Return: number of characters
*/
int print_dec(va_list args)
{
        int i = 0;
        int count = 0;
        int num;
        int arr[10];
        char x[1];

        num = va_arg(args, int);

        while (num != 0)
        {
                arr[i] = (num % 10);
                num = num / 10;
                if (num == 0)
                        break;
                i++;
        }
        while (i >= 0)
        {
                x[0] = ('0' + arr[i]);
                count += write(1, x, 1);
                i--;
        }
        return (count);
}
