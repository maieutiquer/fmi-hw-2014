#include <iostream>

using namespace std;


bool hasExactlyThreeDigits(int number) {
    string stringRepresentationOfNumber = to_string(number);
    int numberLength = stringRepresentationOfNumber.length();
    if (numberLength == 3) {
        return true;
    } else {
        return false;
    }
}

bool hasZero(int number) {
    string stringRepresentationOfNumber = to_string(number);
    int numberLength = stringRepresentationOfNumber.length();
    for (int i = 0; i < numberLength; i++) {
        if (stringRepresentationOfNumber[i] == '0') {
            return true;
        }
    }
    return false;
}

/**
* Checks if a number is divisible by each of its digits.
*/
bool multipleOfOwnDigits(int number) {
    string stringRepresentationOfNumber = to_string(number);
    int numberLength = stringRepresentationOfNumber.length();
    for (int i = 0; i < numberLength; i++) {
        if (number % (stringRepresentationOfNumber[i] - '0') != 0) {
            return false;
        }
    }
    return true;
}

int sumOfDigits(int number) {
    string stringRepresentationOfNumber = to_string(number);
    int numberLength = stringRepresentationOfNumber.length();
    int sum = 0;
    for (int i = 0; i < numberLength; i++) {
        sum += stringRepresentationOfNumber[i] - '0';
    }
    return sum;
}

int productOfDigits(int number) {
    string stringRepresentationOfNumber = to_string(number);
    int numberLength = stringRepresentationOfNumber.length();
    int product = 1;
    for (int i = 0; i < numberLength; i++) {
        product *= stringRepresentationOfNumber[i] - '0';
    }
    return product;
}

int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

int main() {
    int number;
    do {
        number = takeInput("a three-digit number that has no zero in its digits");
    } while (hasExactlyThreeDigits(number) && hasZero(number));

    if (multipleOfOwnDigits(number)) {
        cout << "Yes " << sumOfDigits(number) << "\n";
    } else {
        cout << "no " << productOfDigits(number) << "\n";
    }

    return 0;
}
