#ifndef IO_H
#define IO_H

#include "patient.h"

int getTerminalWidth();
void printCenteredMessage(const char* message, int terminalWidth);
void printDashes(int terminalWidth);
void print_medical_center(int terminal_width);
void print_centered_text(int terminal_width);
void getInput(const char *prompt, char *buffer, size_t size);
int getChoice();
void printMessage(const char *message);
void printError(const char *error);
void showLoginMenu();
void showMainMenu();
void showSelectedOption(const char* option, int terminal_Width);
void loadFromFile(const char *filename, Patient patients[], int *count);
void saveToFile(const char *filename, const Patient patients[], int count);

#endif
