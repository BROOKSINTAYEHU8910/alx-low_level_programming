#include "main.h"

/**
 * print_error_usage - Print error message for incorrect usage
 * @message: The error message to print
 * @exit_code: The exit code to use
 */
void print_error_usage(const char *message, int exit_code)
{
	dprintf(STDERR_FILENO, "%s", message);
	exit(exit_code);
}

/**
 * copy_file - Copy the content of one file to another
 * @source: The source file descriptor
 * @destination: The destination file descriptor
 */
void copy_file(int source, int destination)
{
	char buffer[1024];
	ssize_t read_file;

	while ((read_file = read(source, buffer, 1024)) > 0)
	{
		if (write(destination, buffer, read_file) != read_file)
		{
			close(source);
			close(destination);
			print_error_usage("Error: Can't write to destination file\n", 99);
		}
	}

	if (read_file < 0)
	{
		close(source);
		print_error_usage("Error: Can't read from source file\n", 98);
	}
}

/**
 * main - A program that copies the content of a file to another
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings that holds the arguments
 *
 * Return: On success, returns 0
 */
int main(int argc, char *argv[])
{
	int fp_source, fp_dst;

	if (argc != 3)
		print_error_usage("Usage: cp file_from file_to\n", 97);

	fp_source = open(argv[1], O_RDONLY);
	if (fp_source < 0)
		print_error_usage("Error: Can't read from source file\n", 98);

	fp_dst = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fp_dst < 0)
	{
		close(fp_source);
		print_error_usage("Error: Can't write to destination file\n", 99);
	}

	copy_file(fp_source, fp_dst);

	if (close(fp_source) < 0 || close(fp_dst) < 0)
	{
		if (close(fp_source) < 0)
			print_error_usage("Error: Can't close source file descriptor\n", 100);

		if (close(fp_dst) < 0)
			print_error_usage("Error: Can't close destination file descriptor\n", 100);
	}

	return (0);
}

