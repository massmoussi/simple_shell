#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - entry simple shell
 *
 * retun: rsult for my command 
 */

extern char **environ;


int main(int argc, char **argv)
{
	char *userInput = NULL;
	size_t len = 0;

	while (1)
	{
		printf("Massmousi: $ ");
		
ssize_t bytesRead = getline(&userInput, &len, stdin);

if (bytesRead == -1) {
    
    break;
}
		 if (bytesRead > 1) {
			userInput[strcspn(userInput, "\n")] = '\0';

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
			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("Error:");
				return 1;
			}

			if (child_pid == 0)
			{
				execvp(args[0], args);
				fprintf(stderr ,"%s: No such file or directory\n", argv[0]);
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
			
		}
	}

	free(userInput);

	return (0);
}

