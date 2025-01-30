#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    char id[100];
    char enrollmentNo[100];
    char name[100];
    int age;
    char gender[100];
    char phone[100];
    char address[100];
    char diagnosis[100];
} Patient;

void addPatient(Patient patients[], int *count);
void listPatients(const Patient patients[], int count);
int searchPatient(const Patient patients[], int count, char *id);
void editPatient(Patient patients[], int count);
void deletePatient(Patient patients[], int *count);


#endif
