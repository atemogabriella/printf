#include <unistd.h>
/**
 * _write - writes the character to standard output
 * @c: character to be printed
 * Return: on success 1
 * On error, -1 is returned
 */
int _write(char c)
{
	return (write(1, &c, 1));
}
