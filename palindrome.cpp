#include <iostream>

using namespace std;


bool isPalindrome(int n) {
    string number = to_string(n);
    int numberLength = number.length();
    for (int i = 0; i < numberLength; i++) {
        if (number[i] != number[numberLength - 1 - i]) {
            return false;
        }
    }
    return true;
}

int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

int main() {
    int number;
    number = takeInput("number");

    if (isPalindrome(number)) {
        cout << number << " is a palindrome.\n";
    } else {
        cout << number << " is not a palindrome.\n";
    }

    return 0;
}
