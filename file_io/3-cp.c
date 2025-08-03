#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints error message and exits with given code
 * @code: Exit code
 * @message: Error format string
 * @arg: Argument to format string (e.g., filename)
 */
void error_exit(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
 * prepare_files - Validates arguments, checks file conflict, opens files
 * @argc: Number of command-line arguments
 * @argv: Array of argument strings (argument vector)
 * @fd_from: Pointer to file descriptor for source file
 * @fd_to: Pointer to file descriptor for destination file
 * @buffer: Buffer used to read file content
 * @read_bytes: Pointer to number of bytes read into buffer
 */
void prepare_files(int argc, char *argv[], int *fd_from, int *fd_to,
				   char *buffer, ssize_t *read_bytes)
{
	struct stat st_from, st_to;
	int file_to_exists = 0;

	if (argc != 3)

	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if (stat(argv[1], &st_from) == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	if (stat(argv[2], &st_to) == 0)
	{
		file_to_exists = 1;
		if (st_from.st_ino == st_to.st_ino && st_from.st_dev == st_to.st_dev)
		{
			dprintf(STDERR_FILENO, "Error: %s and %s are the same file\n",
					argv[1], argv[2]);
			exit(100);
		}
	}
	else if (errno != ENOENT)
		error_exit(99, "Error: Can't write to %s\n", argv[2]);
	*fd_from = open(argv[1], O_RDONLY);
	if (*fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	*read_bytes = read(*fd_from, buffer, BUFFER_SIZE);
	if (*read_bytes == -1)
	{
		close(*fd_from);
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}
	*fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		close(*fd_from);
		error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}
	if (!file_to_exists)
		fchmod(*fd_to, 0664);
}

/**
 * main - Entry point, handles file copy logic
 * @argc: Argument count
 * @argv: Argument values
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t read_bytes, written_bytes;
	ssize_t total_written;
	char buffer[BUFFER_SIZE];

	prepare_files(argc, argv, &fd_from, &fd_to, buffer, &read_bytes);
	while (read_bytes > 0)
	{
		total_written = 0;
		while (total_written < read_bytes)
		{
			written_bytes = write(fd_to, buffer + total_written,
			read_bytes - total_written);
			if (written_bytes == -1)
			{
				close(fd_from);
				close(fd_to);
				error_exit(99, "Error: Can't write to %s\n", argv[2]);
			}
			total_written += written_bytes;
		}
		read_bytes = read(fd_from, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			close(fd_from);
			close(fd_to);
			error_exit(98, "Error: Can't read from file %s\n", argv[1]);
		}
	}
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}
