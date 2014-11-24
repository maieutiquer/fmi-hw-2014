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

    // TODO: change messege text
    if (isPalindrome(number)) {
        cout << "MESSAGE_TRUE\n";
    } else {
        cout << "MESSAGE_FALSE\n";
    }

    return 0;
}
