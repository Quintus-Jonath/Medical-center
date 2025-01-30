#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "io.h"

int getTerminalWidth() {
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
    return 80;  // Default width if detection fails
  }
  return ws.ws_col;
}

void printCenteredMessage(const char* message, int terminal_Width) {
  int padding = (terminal_Width - strlen(message)) / 2;
  for (int i = 0; i < padding; i++) {
    fprintf(stdout, " ");
  }
  fprintf(stdout, "%s\n", message);
}

void printDashes(int terminal_Width) {
  for (int i = 0; i < terminal_Width; i++) {
    fprintf(stdout, "-");
  }
  fprintf(stdout, "\n");
}

void getInput(const char *prompt, char *buffer, size_t size) {
  fprintf(stdout, "%s", prompt);
  if (fgets(buffer, size, stdin)) {
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
  }
}

int getChoice() {
  char buffer[10];
  getInput("\n Choose an option: ", buffer, sizeof(buffer));
  return atoi(buffer); // Convert to integer
}

void printMessage(const char *message) {
  fprintf(stdout, "%s\n", message);
}

void printError(const char *error) {
  fprintf(stderr, "\n Error: %s\n", error);
}

void showLoginMenu() {
  printMessage("\n 1. Login");
  printMessage(" 2. Register");
}

void showMainMenu() {
  printMessage("\n 1. Add Patient");
  printMessage(" 2. List All Patients");
  printMessage(" 3. Search Patient");
  printMessage(" 4. Edit Patient");
  printMessage(" 5. Delete Patient");
  printMessage(" 6. Save & Exit");
}

void showSelectedOption(const char* option, int terminalWidth) {
  printMessage("\n");
  printDashes(terminalWidth);
  printCenteredMessage(option, terminalWidth);
  printDashes(terminalWidth);
}


void loadFromFile(const char *filename, Patient patients[], int *count) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, " Error: Could not open file %s for reading.\n", filename);
    return;
  }
  *count = 0;
  while (fread(&patients[*count], sizeof(Patient), 1, file)) {
    (*count)++;
  }
  fclose(file);
}

void saveToFile(const char *filename, const Patient patients[], int count) {
  FILE *file = fopen(filename, "w");
  if (!file) {
    fprintf(stderr, " Error: Could not open file %s for writing.\n", filename);
    return;
  }
  for (int i = 0; i < count; i++) {
    fwrite(&patients[i], sizeof(Patient), 1, file);
  }
  fclose(file);
}