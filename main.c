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

	while (1)
	{	
		printf("$ ");
	       	ssize_t chars_read;
		chars_read = getline(&command, &bufsize, stdin);
		if (chars_read == -1) {
			if (feof(stdin)) {
			       	printf("\n");
				break;
			} else {
				perror("error");
			}
		}	
		printf("%s", command);
	}
	return (0);
}
