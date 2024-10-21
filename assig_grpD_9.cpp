/*
A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” is a palindrome, as can be seen by examining the characters “poor danisina droop” and observing that they are the same forward and backward. One way to check for a palindrome is to reverse the characters in the string and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program with functions-
⦁ To print original string followed by reversed string using stack
⦁ To check whether given string is palindrome or not
*/

#include <iostream>
#include <stack>

bool isAlphanumeric(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');  // Convert uppercase to lowercase
    }
    return ch;
}

void printReversedString(const std::string& str) {
    std::stack<char> s;

    // Push all alphanumeric characters onto the stack
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (isAlphanumeric(ch)) {
            s.push(ch);
        }
    }

    // Print original string
    std::cout << "Original String: " << str << std::endl;

    // Print reversed string
    std::cout << "Reversed String: ";
    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
    std::cout << std::endl;
}

bool isPalindrome(const std::string& str) {
    std::stack<char> s;
    std::string filteredStr;

    // Filter the string to ignore punctuation, capitalization, and spaces
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (isAlphanumeric(ch)) {
            filteredStr += toLower(ch); // Append lowercase characters to filteredStr
            s.push(toLower(ch)); // Push lowercase characters to stack
        }
    }

    // Check if the filtered string is a palindrome
    std::string reversedFilteredStr;
    while (!s.empty()) {
        reversedFilteredStr += s.top();
        s.pop();
    }

    // Compare the filtered string with its reversed version
    for (size_t i = 0; i < filteredStr.length(); ++i) {
        if (filteredStr[i] != reversedFilteredStr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    printReversedString(input);

    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}
