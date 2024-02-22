#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	char *userInput = NULL;
	size_t len = 0;

	while (1)
	{
		printf("Massmousi: $ ");

		if (getline(&userInput, &len, stdin) != -1)
		{
			userInput[strcspn(userInput, "\n")] = '\0';

			printf(" %s\n", userInput);

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

			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("Error:");
				return 1;
			}

			if (child_pid == 0)
			{
				execvp(args[0], args);
				perror("execvp");
				exit(1);
			}
			else
			{
				wait(NULL);

				for (int j = 0; j < i; j++)
				{
					free(args[j]);
				}
			}
		}
		else
		{
			printf("Error reading input.\n");
		}
	}

	free(userInput);

	return (0);
}
