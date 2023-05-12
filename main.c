#include "main.h"
/**
 * Main - a shell to interpret command
 *
 *
 *Return: 0 Always
 */
int main()
{
char command[100];
while (1){
printf("$ ");
fgets(command,sizeof(command), stdin);
printf("%s", command);
}
return (0);
}
