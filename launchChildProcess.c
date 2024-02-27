#include "main.h"

/**
 * launchChildProcess - function handle PID creations
 * @args: pointer to user argument
 */
void launchChildProcess(char *args[])
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
	perror("Error:");
	exit(1);
	}

	if (child_pid == 0)
	{
	execvp(args[0], args);
	fprintf(stderr, "%s: No such file or directory\n", args[0]);
	exit(1);
	}
	else
	{
	wait(NULL);
	}
}

