#include <stdio.h>
#include <string.h>
#include "patient.h"

void addPatient(Patient patients[], int *count) {
    char buffer[100];

    fprintf(stdout, "\n Enter ID: ");
    fgets(patients[*count].id, sizeof(patients[*count].id), stdin);
    strtok(patients[*count].id, "\n"); // Remove trailing newline

    fprintf(stdout, " Enter Name: ");
    fgets(patients[*count].name, sizeof(patients[*count].name), stdin);
    strtok(patients[*count].name, "\n");

    fprintf(stdout, " Enter Age: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &patients[*count].age);

    fprintf(stdout, " Enter Gender: ");
    fgets(patients[*count].gender, sizeof(patients[*count].gender), stdin);
    strtok(patients[*count].gender, "\n");

    fprintf(stdout, " Enter Phone: ");
    fgets(patients[*count].phone, sizeof(patients[*count].phone), stdin);
    strtok(patients[*count].phone, "\n");

    fprintf(stdout, " Enter Address: ");
    fgets(patients[*count].address, sizeof(patients[*count].address), stdin);
    strtok(patients[*count].address, "\n");

    fprintf(stdout, " Enter Diagnosis: ");
    fgets(patients[*count].diagnosis, sizeof(patients[*count].diagnosis), stdin);
    strtok(patients[*count].diagnosis, "\n");

    (*count)++;
    fprintf(stdout, "\n Patient added successfully!\n\n");
}

void listPatients(const Patient patients[], int count) {
    fprintf(stdout, "\n");
    for (int i = 0; i < count; i++) {
        fprintf(stdout, " ID: %s\n Name: %s\n Age: %d\n Gender: %s\n Phone: %s\n Address: %s\n Diagnosis: %s\n\n",
                patients[i].id, patients[i].name, patients[i].age, patients[i].gender,
                patients[i].phone, patients[i].address, patients[i].diagnosis);
    }
}

int searchPatient(const Patient patients[], int count, char *id) {
    for (int i = 0; i < count; i++) {
        if (strcmp(patients[i].id, id) == 0) {
            fprintf(stdout, "\n Found Patient\n\n ID: %s\n Name: %s\n Age: %d\n Gender: %s\n Phone: %s\n Address: %s\n Diagnosis: %s\n\n",
                    patients[i].id, patients[i].name, patients[i].age, patients[i].gender,
                    patients[i].phone, patients[i].address, patients[i].diagnosis);
            return i;
        }
    }
    fprintf(stderr, "\n Patient not found.\n\n");
    return -1;
}

void editPatient(Patient patients[], int count) {
    char id[20];
    char buffer[100];
    int index;

    fprintf(stdout, "\n Enter Patient ID to edit: ");
    fgets(id, sizeof(id), stdin);
    strtok(id, "\n");

    index = searchPatient(patients, count, id);

    if (index != -1) {
        fprintf(stdout, " Editing Patient with ID: %s\n", id);

        fprintf(stdout, " Enter New Name (or press Enter to keep current: %s): ", patients[index].name);
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 1) {
            strtok(buffer, "\n");
            strcpy(patients[index].name, buffer);
        }

        fprintf(stdout, " Enter New Age (or press Enter to keep current: %d): ", patients[index].age);
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 1) {
            sscanf(buffer, "%d", &patients[index].age);
        }

        fprintf(stdout, " Enter New Gender (or press Enter to keep current: %s): ", patients[index].gender);
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 1) {
            strtok(buffer, "\n");
            strcpy(patients[index].gender, buffer);
        }

        fprintf(stdout, " Enter New Phone (or press Enter to keep current: %s): ", patients[index].phone);
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 1) {
            strtok(buffer, "\n");
            strcpy(patients[index].phone, buffer);
        }

        fprintf(stdout, " Enter New Address (or press Enter to keep current: %s): ", patients[index].address);
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 1) {
            strtok(buffer, "\n");
            strcpy(patients[index].address, buffer);
        }

        fprintf(stdout, " Enter New Diagnosis (or press Enter to keep current: %s): ", patients[index].diagnosis);
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 1) {
            strtok(buffer, "\n");
            strcpy(patients[index].diagnosis, buffer);
        }

        fprintf(stdout, "\n Patient updated successfully!\n\n");
    }
}

void deletePatient(Patient patients[], int *count) {
    char id[20];
    int index;

    fprintf(stdout, "\n Enter Patient ID to delete: ");
    fgets(id, sizeof(id), stdin);
    strtok(id, "\n");

    index = searchPatient(patients, *count, id);

    if (index != -1) {
        for (int i = index; i < (*count) - 1; i++) {
            patients[i] = patients[i + 1];
        }
        (*count)--;
        fprintf(stdout, "\n Patient with ID %s deleted successfully!\n\n", id);
    }
}
