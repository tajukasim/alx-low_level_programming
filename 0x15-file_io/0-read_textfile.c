#include "main.h"

/**
 * read_textfile - read a text file and print it to stdout
 * @filename: the name of the file to read
 * @letters: the number of letters to be read and printed
 *
 * Return: If filename is NULL, the file cannot be opened or read, or
 * write fails or returns an unexpected number of bytes, return 0.
 * Otherwise, return the actual number of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf = NULL;
	ssize_t c_read;
	ssize_t c_written;
	int fd;

	if (!(f_name && lett))
		return (0);

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * lett);
	if (!buf)
		return (0);

	c_read = read(fd, buf, lett);
	close(fd);

	if (c_read < 0)
	{
		free(buf);
		return (0);
	}
	if (!c_read)
		c_read = lett;

	c_written = write(STDOUT_FILENO, buf, c_read);
	free(buf);

	if (c_written < 0)
		return (0);

	return (c_written);
