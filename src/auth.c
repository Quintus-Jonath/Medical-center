#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "io.h"

int login(const char *filename) {
	char username[50], password[50], storedUser[50], storedPass[50], headerMessage[50];
	int terminal_width = getTerminalWidth();
	FILE *file;

	strcpy(headerMessage, "User");
	showSelectedOption(headerMessage, terminal_width);
	getInput("\n Enter username: ", username, sizeof(username));
	getInput(" Enter password: ", password, sizeof(password));

	file = fopen(filename, "r");
	if (!file) {
		printError(" Unable to open user file.");
		return 0;
	}

	while (fscanf(file, "%s %s", storedUser, storedPass) != EOF) {
		if (strcmp(username, storedUser) == 0 && strcmp(password, storedPass) == 0) {
			fclose(file);
			printMessage(" Login successful!\n");
			return 1;
		}
	}
	fclose(file);
	printError(" Invalid username or password.");
	return 0;
}

void registerUser(const char *filename) {
	char username[50], password[50], headerMessage[50];
	int terminal_width = getTerminalWidth();
	FILE *file;

	strcpy(headerMessage, "Register");
	showSelectedOption(headerMessage, terminal_width);
	getInput("\n Enter new username: ", username, sizeof(username));
	getInput(" Enter new password: ", password, sizeof(password));

	file = fopen(filename, "a");
	if (!file) {
		printError(" Unable to open user file.");
		return;
	}

	fprintf(file, "%s %s\n", username, password);
	fclose(file);
	printMessage(" User registered successfully!\n");
}
