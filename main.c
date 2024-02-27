#include "main.h"

/**
 * main - entrypoint
 * Description: entry function for a simpleshell
 * Return: 0 if Success
 */

int main(void)
{
	char *userInput = NULL;
	size_t len = 0;
	ssize_t bytesRead;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

	bytesRead = getline(&userInput, &len, stdin);

	if (bytesRead == -1)
	{
		break;
	}

	if (bytesRead > 1)
	{
	userInput[strcspn(userInput, "\n")] = '\0';

	executeCommand(userInput);

	}
	else
	{
	}
	}

	free(userInput);

	return (0);
}

