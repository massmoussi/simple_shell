#include "main.h"

void executeCommand(char *userInput)
{
	char *token = strtok(userInput, " ");
	int i = 0;
	char *args[32];

	while (token != NULL && i < 31)
	{
	if ((args[i] = strdup(token)) == NULL)
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
	launchChildProcess(args, i);
	}

	for (int j = 0; j < i; j++)
	{
	free(args[j]);
	}
}

	void printEnvironmentVariables(void)

{
	char **env = environ;
	while (*env != NULL)
	{
	printf("%s\n", *env);
	env++;
	}
}

