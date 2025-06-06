#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

// Function to normalize the string (remove non-alphanumeric and convert to lowercase)
std::string normalize(const std::string& str) {
    std::string result;
    for (char ch : str) {
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            result += std::tolower(static_cast<unsigned char>(ch));
        }
    }
    return result;
}

// Recursive function to check if a string is a palindrome
bool isPalindrome(const std::string& str, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (str[left] != str[right]) {
        return false;
    }
    return isPalindrome(str, left + 1, right - 1);
}

// Overloaded function to simplify calling isPalindrome
bool isPalindrome(const std::string& str) {
    std::string normalized = normalize(str);
    return isPalindrome(normalized, 0, normalized.length() - 1);
}

int main() {
    std::vector<std::string> strings;
    std::string input;

    std::cout << "Enter 10 strings:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "String " << (i + 1) << ": ";
        std::getline(std::cin, input);
        strings.push_back(input);
    }

    std::cout << "\nPalindrome Test Results:\n";
    for (const std::string& s : strings) {
        bool result = isPalindrome(s);
        std::cout << "\"" << s << "\" is " 
                  << (result ? "" : "not ") 
                  << "a palindrome.\n";
    }

    return 0;
}