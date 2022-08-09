#include "shell.h"

/**
 * count_words - A function that counts how
 *               many words are in a string.
 *
 *@string: The string containing the words to count.
 *
 *
 *Return: The word count inside the string.
 *
 */

int count_words(char *string)
{
	int count = 0, idx = 0;

	while (string[idx] != '\0')
	{
		while (string[idx] == ' ')
		{
			idx++;
		}
		while (string[idx] != ' ' && string[idx] != '\0')
		{
			if (string[idx + 1] == ' ' || string[idx + 1] == '\0')
			{
				count++;
			}
			idx++;
		}
		if (string[idx] == '\0')
		{
			return (count);
		}
		idx++;
	}
	return (count);
}
