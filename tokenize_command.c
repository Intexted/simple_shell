#include "main.h"

/**
 * tokenize_command - to tokenize command using strtok
 *
 * @command: the string command input
 * @args: address of tokenized command
 *
 * Return: Void
 */
void tokenize_command(char *command, char *args[])
{
	char *token;
	int i = 0;

	token = strtok(command, " ");
	while (token != NULL && i < COMMAND_LENGTH - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
