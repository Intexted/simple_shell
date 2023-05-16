#include "main.h"
/**
 * main - a shell to interpret command
 *
 *
 *Return: 0 Always
 */


int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;
	char *token;
	char *args[COMMAND_LENGTH];
	pid_t pid;

	while (1)
	{
		printf("$ ");
		chars_read = getline(&command, &bufsize, stdin);
		if (chars_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
		}

		command[strcspn(command, "\n")] = '\0';

		token = strtok(command, " ");
		if (token != NULL)
		{
			args[0] = token;
			args[1] = NULL;
		} else
		{
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			execvp(args[0], args);
			perror("execvp");
			exit(EXIT_FAILURE);
		} else if (pid > 0)
		{
			wait(NULL);
		} else
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
