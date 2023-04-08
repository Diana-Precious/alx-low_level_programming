#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - read text file printed to STDOUT.
 * @filename: text file being read
 * @letters: nuber of letters to be read
 * Return: w- actual number of bytes read & printed
 * 0 when it fails or file name is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
