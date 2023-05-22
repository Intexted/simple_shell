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
	int i;
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
			else if (ferror(stdin))
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}

		command[strcspn(command, "\n")] = '\0';
		token = strtok(command, " ");
		if (token != NULL)
		{
			args[0] = token;
			i = 1;
		} else
		{
			continue;
		}
		while ((token = strtok(NULL, " ")) != NULL)
		{
			args[i++] = token;
		}
		args[i] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			break;
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
	free(command);
	return (0);
}

