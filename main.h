#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

void executeCommand(char *userInput);
void printEnvironmentVariables(void);
void launchChildProcess(char *args[], int argCount);

#endif /* MAIN_H */

