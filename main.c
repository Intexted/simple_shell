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
	char *args[COMMAND_LENGTH];

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
		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		tokenize_command(command, args);
		execute_command(args);
	}
	free(command);
	return (0);
}

