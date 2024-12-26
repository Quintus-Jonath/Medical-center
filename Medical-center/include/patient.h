#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    char id[20];
    char name[50];
    int age;
    char gender[10];
    char phone[15];
    char address[100];
    char diagnosis[100];
} Patient;

void addPatient(Patient patients[], int *count);
void listPatients(const Patient patients[], int count);
int searchPatient(const Patient patients[], int count, char *id);
void editPatient(Patient patients[], int count);
void deletePatient(Patient patients[], int *count);


#endif
