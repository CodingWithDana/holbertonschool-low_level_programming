#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
/**
  * error_exit - handle error messages and exit with given code
  * @code: exit code (97, 98, 99, 100)
  * @message: error message format string 
  * @arg: additional arguments (filename, file descriptor)
  */
void error_exit(int code, const char *message, int arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit (code);
}

/**
  * main - copy content from file_from to file_to
  * @argc: number of command line arguments
  * @argv: array of arguments
  * Return: 0 if successful, otherwise exit with corresponding error code if failed
  */
int main(int argc, char *argv[])
{
	int fd_from;
       	int fd_to;
	int read_bytes;
	int written_bytes;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", (int)(intptr_t)argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to %s\n", (int)(intptr_t)argv[2]);
	}
	fchmod(fd_to, 0664);

	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		written_bytes = write(fd_to, buffer, read_bytes);

		if (written_bytes != read_bytes)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to %s\n", (int)(intptr_t)argv[2]);
		}
	}

	if (read_bytes == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file %s\n", (int)(intptr_t)argv[1]);
	}
	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_to);

	return (0);
}
