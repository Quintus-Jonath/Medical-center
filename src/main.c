#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "patient.h"
#include "io.h"
#include "auth.h"

#define MAX_PATIENTS 100
#define FILE_NAME "patients.dat"
#define USER_FILE "users.dat"

int main() {
	Patient patients[MAX_PATIENTS];
	char headerMessage[50];
	int count = 0;
	int choice;
	int terminal_width = getTerminalWidth();
	
	strcpy(headerMessage, "UWU - Medical Center");
	showSelectedOption(headerMessage, terminal_width);

	// Authentication
	showLoginMenu();
	choice = getChoice();
	if (choice == 1) {
		if (!login(USER_FILE)) {
			return 0;
		}
	} else if (choice == 2) {
		registerUser(USER_FILE);
		return 0;
	} else {
		printError(" Invalid choice.\n");
		return 0;
	}

	// Load patient data
	loadFromFile(FILE_NAME, patients, &count);


	// Main menu loop
	do {
		strcpy(headerMessage, "Patient Management");
		showSelectedOption(headerMessage, terminal_width);
			
		showMainMenu();
		choice = getChoice();

		switch (choice) {
			case 1:
				strcpy(headerMessage, "Add Patient");
				showSelectedOption(headerMessage, terminal_width);
				if (count < MAX_PATIENTS) {
					addPatient(patients, &count);
				} else {
					printError(" Patient list is full.\n");
				}
				break;
			case 2:
				strcpy(headerMessage, "List all Patients");
				showSelectedOption(headerMessage, terminal_width);
				listPatients(patients, count);
					break;
			case 3: {
				char id[20];
				getInput("\n Enter Patient ID to search: ", id, sizeof(id));
				strcpy(headerMessage, "Search Patient");
				showSelectedOption(headerMessage, terminal_width);
				searchPatient(patients, count, id);
				break;
			}
			case 4:
				strcpy(headerMessage, "Edit Patient");
				showSelectedOption(headerMessage, terminal_width);
				editPatient(patients, count);
				break;
			case 5:
				strcpy(headerMessage, "Delete Patient");
				showSelectedOption(headerMessage, terminal_width);
				deletePatient(patients, &count);
				break;
			case 6:
				strcpy(headerMessage, "Exit");
				showSelectedOption(headerMessage, terminal_width);
				saveToFile(FILE_NAME, patients, count);
				break;
			default:
				printError(" Invalid choice.");
		}
	} while (choice != 6);

	return 0;
}
