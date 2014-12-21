#include <iostream>

using namespace std;


bool hasExactlyThreeDigits(int number) {
    string numberAsString = to_string(number);
    int numberLength = numberAsString.length();
    if (numberLength == 3) {
        return true;
    } else {
        return false;
    }
}

bool hasZero(int number) {
    string numberAsString = to_string(number);
    int numberLength = numberAsString.length();

    for (int i = 0; i < numberLength; i++) {
        if (numberAsString[i] == '0') {
            return true;
        }
    }
    return false;
}

/**
* Checks if a number is divisible by each of its digits.
*/
bool multipleOfOwnDigits(int number) {
    string numberAsString = to_string(number);
    int numberLength = numberAsString.length();

    for (int i = 0; i < numberLength; i++) {
        if (number % (numberAsString[i] - '0') != 0) {
            return false;
        }
    }
    return true;
}

int sumOfDigits(int number) {
    string numberAsString = to_string(number);
    int numberLength = numberAsString.length();
    int sum = 0;

    for (int i = 0; i < numberLength; i++) {
        sum += numberAsString[i] - '0';
    }
    return sum;
}

int productOfDigits(int number) {
    string numberAsString = to_string(number);
    int numberLength = numberAsString.length();
    int product = 1;

    for (int i = 0; i < numberLength; i++) {
        product *= numberAsString[i] - '0';
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
    } while (!hasExactlyThreeDigits(number) || hasZero(number));

    if (multipleOfOwnDigits(number)) {
        cout << "Yes " << sumOfDigits(number) << "\n";
    } else {
        cout << "no " << productOfDigits(number) << "\n";
    }

}
