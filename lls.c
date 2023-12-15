#include "shell.h"

/**
 * _memcpy - Copies memory from one location to another.
 * @newptr: Pointer to the destination.
 * @ptr: Pointer to the source.
 * @size: Number of bytes to copy.
 * Return: None.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - Reallocates memory for a block of memory.
 * @ptr: Pointer to the original block of memory.
 * @old_size: Original size of the block.
 * @new_size: New size of the block.
 * Return: Pointer to the reallocated block of memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	 void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - Reallocates memory for an array of pointers.
 * @ptr: Pointer to the original array.
 * @old_size: Original size of the array.
 * @new_size: New size of the array.
 * Return: Pointer to the reallocated array of pointers.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
