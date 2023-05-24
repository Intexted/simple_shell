#include "main.h"

/**
 *execute_command - to execute command with execvp
 *
 *@args: string command to be executed
 *
 *Return: Void
 */
void execute_command(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	} else if (pid > 0)
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	} else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
