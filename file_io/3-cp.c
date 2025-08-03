#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
  * error_exit - handle error messages and exit with given code
  * @code: exit code (97, 98, 99, 100)
  * @message: error message format string 
  * @arg: additional arguments (filename, file descriptor)
  */
void error_exit(int code, const char *message, const char *arg)
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
    int fd_to = -1;
	ssize_t read_bytes;
	ssize_t written_bytes;
	ssize_t total_written;
	char buffer[BUFFER_SIZE];
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
		file_to_exists = 1;
	else if (errno != ENOENT)
		error_exit(99, "Error: Can't write to %s\n", argv[2]);

	if (file_to_exists && st_from.st_ino == st_to.st_ino && st_from.st_dev == st_to.st_dev)
	{
		dprintf(STDERR_FILENO, "Error: %s and %s are the same file\n", argv[1], argv[2]);
		exit(100);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	if (!file_to_exists)
		fchmod(fd_to, 0664);

	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
        total_written = 0;
        while (total_written < read_bytes)
		{
			written_bytes = write(fd_to, buffer + total_written, read_bytes - total_written);
			if (written_bytes == -1)
			{	
				close(fd_from);
				close(fd_to);
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				exit(99);
            }
			total_written += written_bytes;
		}
	}

	if (read_bytes == -1)
    {
        close(fd_from);
		if (fd_to != -1)
			close(fd_to);
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
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