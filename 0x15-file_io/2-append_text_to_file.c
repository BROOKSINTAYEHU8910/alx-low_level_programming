#include "main.h"

/**
 * append_text_to_file - Append text at the end of a file
 * @filename: The name of the file to append to
 * @text_content: The string to add at the end of the file
 *
 * Return: 1 on success or -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fp, result;

	if (filename == NULL)
		return (-1);

	fp = open(filename, O_WRONLY | O_APPEND);
	if (fp == -1)
		return (-1);

	if (text_content != NULL)
	{
		result = write(fp, text_content, strlen(text_content));
		if (result == -1)
		{
			close(fp);
			return (-1);
		}
	}

	close(fp);
	return (1);
}
