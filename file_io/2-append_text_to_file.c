#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
/**
  * append_text_to_file - append text at the end of a file
  * @filename: name of the the file to create
  * @text_content: NULL-terminated string to add to the end of the file
  * Return: 1 if successful, -1 if failed
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t written;
	size_t len = 0;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;

		written = write(fd, text_content, len);
		if (written == -1 || (size_t)written != len)
		{
			close(fd);
			return (-1);
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
