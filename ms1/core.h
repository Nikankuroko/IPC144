/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// Tester Function Prototypes

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// This function guarantees that an integer value is entered and returned. If an invalid value is entered, an error message would be displayed.
int inputInt(void);

// This function guarantees a positive integer value is entered and returned. If a zero or a negative value in entered, an error message would be displayed.
int inputIntPositive(void);

// This function guarantees a positive integer value is entered and returned. If a zero or a negative value in entered, an error message would be displayed.
int inputIntRange(int ln, int un);

// This function guarantees a single char value is entered in the list of correct characters and returned. If an entered character is not in the list of correct characters, it shows  an error message and prompt again.
char inputCharOption(char str[]);

// This function keep a C string value is entered containing the number of char in the range specified by the 2 and 3 arguments.
void inputCString(char* str, int minChar, int maxChar);

// The purpose of this function is to display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(const char* str);
