#include "main.h"

/**
 * main - A program that copies the content of a file to another
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings that holds the arguments
 *
 * Return: On success, returns 0
 */
int main(int argc, char *argv[])
{
	char buffer[1024];
	int fp_source, fp_dst, read_file;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fp_source = open(argv[1], O_RDONLY);
	if (fp_source < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fp_dst = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((read_file = read(fp_source, buffer, 1024)) > 0)
	{
		if (fp_dst < 0 || write(fp_dst, buffer, read_file) != read_file)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fp_source);
			exit(99);
		}
	}

	if (read_file < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(fp_source) < 0 || close(fp_dst) < 0)
	{
		if (close(fp_source) < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fp_source);
		}
		if (close(fp_dst) < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fp_dst);
		}
		exit(100);
	}

	return (0);
}
