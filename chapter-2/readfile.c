#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char* read_from_file(const char* filename, size_t length)
{
	char* buffer;
	int fd;
	ssize_t bytes_read;

	// allocate the buffer.
	buffer = (char*) malloc(length);

	if (buffer == NULL)
		return NULL;

	// open the file
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		// open failed - deallocate buffer before returning
		free(buffer);
		return NULL;
	}

	// read the data
	bytes_read = read(fd, buffer, length);
	if (bytes_read != length)
	{
		// read failed - deallocate buffer and close fd before returning
		free(buffer);
		close(fd);
		return NULL;
	}

	// everything's fine - close file and return
	close(fd);
	return buffer;
}