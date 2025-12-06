#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * main - copies the content of one file to another
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exits with codes 97-100 on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t n_read, n_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		if (close(fd_from) == -1)
			dprintf(2, "Error: Can't close fd %d\n", fd_from), exit(100);
		exit(99);
	}

	while ((n_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		n_written = write(fd_to, buffer, n_read);
		if (n_written != n_read)
		{
			dprintf(2, "Error: Can't write to %s\n", argv[2]);
			if (close(fd_from) == -1)
				dprintf(2, "Error: Can't close fd %d\n", fd_from), exit(100);
			if (close(fd_to) == -1)
				dprintf(2, "Error: Can't close fd %d\n", fd_to), exit(100);
			exit(99);
		}
	}

	if (n_read == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		if (close(fd_from) == -1)
			dprintf(2, "Error: Can't close fd %d\n", fd_from), exit(100);
		if (close(fd_to) == -1)
			dprintf(2, "Error: Can't close fd %d\n", fd_to), exit(100);
		exit(98);
	}

	if (close(fd_from) == -1)
		dprintf(2, "Error: Can't close fd %d\n", fd_from), exit(100);
	if (close(fd_to) == -1)
		dprintf(2, "Error: Can't close fd %d\n", fd_to), exit(100);

	return (0);
}
