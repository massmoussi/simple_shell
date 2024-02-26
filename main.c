#include "main.h"

/**
 * main - entrypoint
 * Description: entry function for a simpleshell
 * @argc: number of argument
 * @argv: pointer to arguent vectors
 * Return: 0 if Success
 */

int main(int argc, char **argv)
{
	char *userInput = NULL;
	size_t len = 0;

	while (1)
	{
		printf("Massmousi: $ ");

	ssize_t bytesRead = getline(&userInput, &len, stdin);

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

