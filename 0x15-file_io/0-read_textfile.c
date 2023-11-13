#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout
 * @filename: The name of the file to be read
 * @letters: The number of letters to read and print
 *
 * Return: The number of letters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t readsUp, filesWritten;
	int fp;
	char *buffer;

	if (filename == NULL)
		return (0);

	fp = open(filename, O_RDONLY);
	if (fp == -1)
		return (0);

	buffer = (char *)malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fp);
		return (0);
	}
	readsUp = read(fp, buffer, letters);
	if (readsUp == -1)
	{
		close(fp);
		free(buffer);
		return (0);
	}

	filesWritten = write(STDOUT_FILENO, buffer, readsUp);
	if (filesWritten == -1 || filesWritten != readsUp)
	{
		close(fp);
		free(buffer);
		return (0);
	}

	close(fp);
	free(buffer);
	return (readsUp);
}
