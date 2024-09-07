/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2


Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include <string.h>



//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int n, eligible_record = 0;

    if (fmt == FMT_TABLE) {
        displayPatientTableHeader();
    }

    for (n = 0; n < max; n++) {
        if (patient[n].patientNumber != 0) {
            displayPatientData(&patient[n], fmt);
            eligible_record = 1;
        }
    }

    if (!eligible_record) {
        printf("*** No records found ***\n\n");
    }

    printf("\n");
}


// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max) {
    int option;

    // Printing menu for user
    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &option);
        printf("\n");

        if (option == 1) {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (option == 2) {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (option != 0);
}

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max) {
    int n, structSize = 0;
    for (n = 0; n < max; n++) {
        if (patient[n].patientNumber != 0) {
            structSize++;
        }
    }
    if (max > structSize) {
        patient[structSize].patientNumber = nextPatientNumber(patient, max);
        inputPatient(patient + structSize);
        printf("*** New patient record added ***\n\n");
        clearInputBuffer();
    }
    else {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array

void editPatient(struct Patient patient[], int max) {
    int pnum, index;
    printf("Enter the patient number: ");
    scanf("%d", &pnum);
    printf("\n");

    if (findPatientIndexByPatientNum(pnum, patient, max) != -1) {
        index = findPatientIndexByPatientNum(pnum, patient, max);
        menuPatientEdit(patient + index);
    }
    else {
        printf("ERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array

void removePatient(struct Patient patient[], int max) {
    int pnum, index;
    char choice;
    printf("Enter the patient number: ");
    scanf("%d", &pnum);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(pnum, patient, max) != -1) {
        index = findPatientIndexByPatientNum(pnum, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &choice);
        

        if (choice == 'n' || choice == 'N') {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }
        else {
            // Assigning patient to safe empty state so that the other function can't access it
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int pnum, index;
    printf("Search by patient number: ");
    scanf("%d", &pnum);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(pnum, patient, max) != -1) {
        index = findPatientIndexByPatientNum(pnum, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");
    }

    else {
        printf("*** No records found ***\n\n");
    }
}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int n, match = 0;
    char phoneNumber[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    printf("\n");

    displayPatientTableHeader();

    for (n = 0; n < max + 1; n++) {
        if (strcmp(patient[n].phone.number, phoneNumber) == 0) {
            printf("%05d %-15s ", patient[n].patientNumber, patient[n].name);
            displayFormattedPhone(patient[n].phone.number);
            printf(" (%s)\n", patient[n].phone.description);
            match++;
        }
    }
    printf("\n");

    if (match == 0) {
        printf("*** No records found ***\n\n");
    }
}


// Get the next highest patient number

int nextPatientNumber(const struct Patient patient[], int max) {
    int nextnum, maxnum = patient[0].patientNumber, n;

    for (n = 0; n < max; n++) {
        if (patient[n].patientNumber > maxnum) {
            maxnum = patient[n].patientNumber;
        }
    }

    nextnum = maxnum + 1;
    return nextnum;
}



// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int n;
    // Iterate through the array to find the patient number
    for (n = 0; n < max; n++) {
        if (patient[n].patientNumber == patientNumber) {
            return n;
        }
    }
    // If anything is not found, -1 is returned
    return -1;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient) {
    int n;
    char name[NAME_LEN];
    
    //show form to get input
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    fgets(name, sizeof(name), stdin);

    // Store name in struct 

    for (n = 0; n < strlen(name) - 1; n++) {
        patient->name[n] = name[n];
    }

    printf("\n");
    inputPhoneData(&patient->phone);
}




// Get user input for phone contact information
void inputPhoneData(struct Phone* phone) {
    int choice, n;
    char inputNumber[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &choice);
    printf("\n");
    if (choice >= 1 && choice <= 3) {
        const char* descriptions[] = { "CELL", "HOME", "WORK" };
        strncpy(phone->description, descriptions[choice - 1], PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
    }
    else if (choice == 4) {
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        phone->number[0] = '\0';
        return;
    }
    else {
        printf("Error:\n");
        return;
    }

    clearInputBuffer();
    printf("Number : ");
    fgets(inputNumber, sizeof(inputNumber), stdin);
    for (n = 0; n < PHONE_LEN + 1; n++) {
        phone->number[n] = inputNumber[n];
        if (inputNumber[n] == '\n') {
            phone->number[n] = '\0';
            break;
        }
    }
    printf("\n");
}


