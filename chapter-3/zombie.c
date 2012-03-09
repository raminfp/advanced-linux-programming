#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t child_pid;

	// create a child process
	child_pid = fork();
	if (child_pid > 0)
	{
		// this is the parent process. sleep for a minute.
		sleep(60);
	}
	else
	{
		// this is the child process. exit immediately.
		exit(0);
	}

	return 0;
}