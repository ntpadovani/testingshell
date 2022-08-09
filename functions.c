#include "shell.h"

/**
 * print_string - A function that prints a string array.
 * @ptr:  Contains the values.
 * Return: The number of characters printed.
 */
int print_string(va_list ptr)
{
	char *store;
	int idx;

	store = va_arg(ptr, char *);

	for (idx = 0; store[idx] != '\0'; idx++)
	{
		if (store[idx] == '\0')
		{
			return ('\0');
		}
		putchar(store[idx]);
	}
	return (idx);
}


/**
 * print_char - A function that prints a char.
 * @ptr:  Contains the values.
 * Return: The number of characters printed.
 */
int print_char(va_list ptr)
{
	char store;

	store = va_arg(ptr, int);

	if (store == '\0')
	{
		return ('\0');
	}
	putchar(store);
	return (1);
}


/**
 * print_int - A function that converts chars to ints.
 * @n: Num to convert.
 * Return: Number of chars converted.
 */
int print_int(int n)
{
	int idx = 1;
	int num = 0;

	if (n < 0)
	{
		putchar('-');
		idx++;
		num = n * -1;
	}
	else
	{
		num = n;
	}
	if (num / 10)
	{
		idx += print_int(num / 10);
	}
	putchar((num % 10) + 48);
	return (idx);
}


/**
 * print_number - Converts integer to signed decimal notation.
 * @ptr:  Contains the values.
 * Return: The number of characters printed.
 */
int print_number(va_list ptr)
{
	int n, count;

	n = va_arg(ptr, int);
	count = print_int(n);
	return (count);
}


