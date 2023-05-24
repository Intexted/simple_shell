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

	int is_interactive = isatty(fileno(stdin));

	while (1)
	{
		if (is_interactive)
		{
			printf("($) ");
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
		}
		else
		{
			chars_read = getline(&command, &bufsize, stdin);
			if (chars_read == -1)
				break;
		}
		command[strcspn(command, "\n")] = '\0';
		tokenize_command(command, args);
	}
	free(command);
	return (0);
}


