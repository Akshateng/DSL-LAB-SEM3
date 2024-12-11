/*
A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” is a palindrome, as can be seen by examining the characters “poor danisina droop” and observing that they are the same forward and backward. One way to check for a palindrome is to reverse the characters in the string and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program with functions-
⦁ To print original string followed by reversed string using stack
⦁ To check whether given string is palindrome or not
*/
#include<iostream>
#include<string.h>
#define max 50
using namespace std;

class STACK {
    private:
        char a[max];
        int top;

    public:
        STACK() {
            top = -1;
        }

        void push(char);
        void reverse();    
        void convert(char[]);
        void palindrome();
};

// Function to push a character onto the stack
void STACK::push(char c) {
    if (top < max - 1) {
        top++;
        a[top] = c;
        a[top+1] = '\0';  // Ensure the string is null-terminated after each push
    }
}

// Function to reverse and print the stack contents
void STACK::reverse() {
    char str[max];

    cout << "\nReversed string is: ";
    
    for (int i = top, j = 0; i >= 0; i--, j++) {
        cout << a[i];
        str[j] = a[i];
    }

    str[top + 1] = '\0';  // Add null terminator to the reversed string
    cout << endl;
}

// Function to remove non-alphanumeric characters and convert to lowercase
void STACK::convert(char str[]) {
    int j, k, len = strlen(str);

    for (j = 0, k = 0; j < len; j++) {
        // Check for alphanumeric characters (letters and digits)
        if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')) {
            // Convert uppercase to lowercase
            if (str[j] >= 'A' && str[j] <= 'Z') {
                str[k] = str[j] + 32;  // Convert to lowercase
            } else {
                str[k] = str[j];
            }
            k++;
        }
    }
    str[k] = '\0';  // Null-terminate the cleaned string

    cout << "\nConverted string (ignoring spaces/punctuation and lowercase): " << str << endl;
}

// Function to check if the string is a palindrome
void STACK::palindrome() {
    char str[max];
    int i, j;

    for (i = top, j = 0; i >= 0; i--, j++) {
        str[j] = a[i];
    }
    str[j] = '\0';

    if (strcmp(str, a) == 0) {
        cout << "\nThe string is a palindrome." << endl;
    } else {
        cout << "\nThe string is not a palindrome." << endl;
    }
}

int main() {
    STACK stack;
    char str[max];
    int i = 0;

    cout << "\nEnter string to be reversed and checked for palindrome:\n";
    cin.getline(str, max);

    // Convert the string (remove non-alphanumeric and convert to lowercase)
    stack.convert(str);

    // Push each character of the string onto the stack
    while (str[i] != '\0') {
        stack.push(str[i]);
        i++;
    }

    // Check if the string is a palindrome
    stack.palindrome();

    // Print the reversed string
    stack.reverse();

    return 0;
}
