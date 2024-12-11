/*
A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” is a palindrome, as can be seen by examining the characters “poor danisina droop” and observing that they are the same forward and backward. One way to check for a palindrome is to reverse the characters in the string and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program with functions-
⦁ To print original string followed by reversed string using stack
⦁ To check whether given string is palindrome or not
*/
#include<iostream>
#include<string.h>
#define MAX 50
using namespace std;

class Stack {
    private:
        char a[MAX];
        int top;
    public:
        Stack() {
            top = -1;
        }

        // Push character onto stack
        void push(char c) {
            if (top < MAX - 1) {
                top++;
                a[top] = c;
            }
        }

        // Reverse the string using the stack
        void reverse() {
            cout << "\nReversed string: ";
            for (int i = top; i >= 0; i--) {
                cout << a[i];
            }
            cout << endl;
        }

        // Convert string to lowercase and remove non-alphabetical characters
        void convert(char str[]) {
            int j = 0, len = strlen(str);

            for (int i = 0; i < len; i++) {
                // Only retain alphanumeric characters and convert to lowercase
                if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
                    if (str[i] >= 'A' && str[i] <= 'Z') {
                        str[j] = str[i] + 32;  // Convert to lowercase
                    } else {
                        str[j] = str[i];
                    }
                    j++;
                }
            }
            str[j] = '\0';  // Null-terminate the cleaned string
            cout << "Converted string after removing spaces and converting to lowercase: " << str << endl;
        }

        // Check if the string is a palindrome
        void palindrome(char str[]) {
            int len = strlen(str);
            int start = 0, end = len - 1;
            while (start < end) {
                if (str[start] != str[end]) {
                    cout << "String is not a palindrome" << endl;
                    return;
                }
                start++;
                end--;
            }
            cout << "String is a palindrome" << endl;
        }

        // Push the cleaned string onto the stack
        void pushCleanedString(char str[]) {
            int i = 0;
            while (str[i] != '\0') {
                push(str[i]);
                i++;
            }
        }
};

int main() {
    Stack stack;
    char str[MAX];

    cout << "Enter the string to be reversed and checked for palindrome: ";
    cin.getline(str, MAX);

    // Convert string by removing non-alphabetical characters and converting to lowercase
    stack.convert(str);

    // Push the cleaned string onto the stack
    stack.pushCleanedString(str);

    // Check if the cleaned string is a palindrome
    stack.palindrome(str);

    // Reverse and display the string using the stack
    stack.reverse();

    return 0;
}
