#include "main.h"

/**
 * create_file - Creates a file
 * @filename: The name of the file to create
 * @text_content: The text content to write to the created file
 *
 * Return: 1 on success or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fp;
	mode_t mode = S_IRUSR | S_IWUSR;
	int result;

	if (filename == NULL)
		return (-1);

	fp = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (fp == -1)
		return (-1);

	if (text_content != NULL)
		result = write(fp, text_content, strlen(text_content));
	if (result == -1)
	{
		close(fp);
		return (-1);
	}

	close(fp);
	return (1);
}
