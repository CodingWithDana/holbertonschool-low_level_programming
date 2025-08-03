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
 * validate_arguments - Checks argument count
 * @argc: Argument count
 */
void validate_arguments(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check_same_file - Verifies source and destination are not the same
 * @file_from: Source file path
 * @file_to: Destination file path
 * @file_to_exists: Pointer to store existence flag
 */
void check_same_file(const char *file_from, const char *file_to, int *file_to_exists)
{
	struct stat st_from, st_to;

	if (stat(file_from, &st_from) == -1)
		error_exit(98, "Error: Can't read from file %s\n", file_from);

	if (stat(file_to, &st_to) == 0)
	{
		*file_to_exists = 1;
		if (st_from.st_ino == st_to.st_ino && st_from.st_dev == st_to.st_dev)
		{
			dprintf(STDERR_FILENO, "Error: %s and %s are the same file\n",
				file_from, file_to);
			exit(100);
		}
	}		
	else if (errno != ENOENT)
	{
		error_exit(99, "Error: Can't write to %s\n", file_to);
	}
}

/**
 * open_file_read - Opens source file for reading
 * @filename: File to open
 * Return: File descriptor
 */
int open_file_read(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		error_exit(98, "Error: Can't read from file %s\n", filename);

	return (fd);
}

/**
 * open_file_write - Opens or creates destination file for writing
 * @filename: File to open
 * @file_to_exists: Whether the file already exists
 * Return: File descriptor
 */
int open_file_write(const char *filename, int file_to_exists)
{
	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	if (!file_to_exists)
		fchmod(fd, 0664);

	return (fd);
}

/**
 * copy_file - Copies data from source to destination
 * @fd_from: Source file descriptor
 * @fd_to: Destination file descriptor
 * @file_from: Source file name for error messages
 */
void copy_file(int fd_from, int fd_to, const char *file_from)
{
	ssize_t read_bytes = 0;
	ssize_t written_bytes;
	ssize_t total_written;
	char buffer[BUFFER_SIZE];

	while (read_bytes > 0)
	{
		total_written = 0;
		while (total_written < read_bytes)
		{
			written_bytes = write(fd_to, buffer + total_written, read_bytes - total_written);
			if (written_bytes == -1)
			{
				close(fd_from);
				close(fd_to);
				error_exit(99, "Error: Can't write to %s\n", file_from);
			}
			total_written += written_bytes;
		}
		read_bytes = read(fd_from, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			close(fd_from);
			close(fd_to);
			error_exit(98, "Error: Can't read from file %s\n", file_from);
		}
	}
}

/**
 * cleanup - Closes both file descriptors with error handling
 * @fd_from: Source file descriptor
 * @fd_to: Destination file descriptor
 */
void cleanup(int fd_from, int fd_to)
{
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
}

/**
 * main - Entry point, handles file copy logic
 * @argc: Argument count
 * @argv: Argument values
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from;
	int fd_to;
	int file_to_exists = 0;
	ssize_t read_bytes;
	char buffer[BUFFER_SIZE];

	validate_arguments(argc);
	check_same_file(argv[1], argv[2], &file_to_exists);
	fd_from = open_file_read(argv[1]);

	/* Precheck read BEFORE opening fd_to */
	read_bytes = read(fd_from, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
	{
		close(fd_from);
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);
	}

	fd_to = open_file_write(argv[2], file_to_exists);
	copy_file(fd_from, fd_to, argv[1]);
	cleanup(fd_from, fd_to);

	return (0);
}
