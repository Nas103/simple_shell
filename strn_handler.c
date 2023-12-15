#include "shell.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string to which @src will be appended
 * @src: Source string to be appended to @dest
 * Return: Pointer to the resulting string (same as @dest)
 *
 * Description: This function appends the content of the source string (@src)
 * to the destination string (@dest). The resulting string is terminated with
 * a null character. The function returns a pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - Copies a string
 * @dest: Destination string where the content of @src will be copied
 * @src: Source string to be copied
 * Return: Pointer to the resulting string (same as @dest)
 *
 * Description: This function copies the content of the source string (@src)
 * to the destination string (@dest). The resulting string is terminated with
 * a null character. The function returns a pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string for comparison
 * @s2: Second string for comparison
 * Return: 0 if strings are equal, positive if s1 > s2, negative if s1 < s2
 *
 * Description: This function compares two strings character by character.
 * It returns an integer less than, equal to, or greater than zero if s1 is
 * found, respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _strchr - Locates a character in a string
 * @s: String to be searched
 * @c: Character to be located
 * Return: Pointer to the first occurrence of @c in @s, or NULL if not found
 *
 * Description: This searches for the first occurrence of chars
 * @c in the string @s. If char is found, a pointer to its location in @s
 * is returned; or returns NULL.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}

/**
 * _strspn - Gets the length of a prefix substring
 * @s: String to be searched
 * @accept: String containing the characters to match
 * Return: Number of characters in the initial segment of @s that match @accept
 *
 * Description: This calculates length of the initial segment of @s,
 * which consists of only the characters found in @accept.
 */
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
