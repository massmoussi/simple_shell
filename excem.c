#include "main.h"


/**
 * executeCommand - function handle user input
 * @userInput: pointer to input provided by user
 */
void executeCommand(char *userInput)
{
	char *token = strtok(userInput, " ");
	int i = 0;
	char *args[32];
	int j;

	while (token != NULL && i < 31)
	{
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup");
			exit(1);
		}
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	if (strcmp(args[0], "exit") == 0)
	{
		free(userInput);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		printEnvironmentVariables();
	}
	else
	{
		launchChildProcess(args);
	}

	for (j = 0; j < i; j++)
	{
		free(args[j]);
	}
}

/**
 * printEnvironmentVariables - function print env
 */
void printEnvironmentVariables(void)
{
	char **env = environ;

	while (*env != NULL)
	{
	printf("%s\n", *env);
	env++;
	}
}
