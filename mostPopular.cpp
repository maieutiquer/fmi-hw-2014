#include <iostream>

using namespace std;


int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

int takeArraySize() {
    int arraySize;
    do {
        arraySize = takeInput("array size");
    } while (arraySize < 10 || arraySize > 20);
    return arraySize;
}

int countTotalDigits(int array[], int arraySize) {
    int totalDigits = 0;
    for (int i = 0; i < arraySize; i++) {
        totalDigits += to_string(array[i]).size();
    }
    return totalDigits;
}

void fillArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        array[i] = takeInput("array[" + to_string(i) + "]");
    }
}

void splitArrayOfIntsToDigits(
        int arrayOfInts[], int arraySize,
        int arrayOfDigits[]) {
    int digitIndex = 0;
    for (int numberIndex = 0; numberIndex < arraySize; numberIndex++) {
        string numberAsString = to_string(arrayOfInts[numberIndex]);
        int numberLength = numberAsString.length();
        for (int i = 0; i < numberLength; i++) {
            arrayOfDigits[digitIndex] = numberAsString[i] - '0';
            digitIndex++;
        }
    }
}

int countOccurences(int number, int array[], int arraySize) {
    int counter = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == number) {
            counter++;
        }
    }
    return counter;
}

int findMostPopularDigit(int array[], int arraySize) {
    int mostPopularDigit = 0;
    int mostOccurences = 0;
    int alreadyCheckedDigits[arraySize];
    for (int i = 0; i < arraySize; i++) {
        bool isAlreadyChecked = countOccurences(array[i], alreadyCheckedDigits, arraySize);
        if (!isAlreadyChecked) {
            int occurences = countOccurences(array[i], array, arraySize);
            if (occurences > mostOccurences) {
                mostOccurences = occurences;
                mostPopularDigit = array[i];
            } else if (occurences == mostOccurences && array[i] < mostPopularDigit) {
                mostPopularDigit = array[i];
            }
            alreadyCheckedDigits[i] = array[i];
        }
    }
    return mostPopularDigit;
}

bool hasEvenNumberOfDigits(int number) {
    return (to_string(number).size() % 2 == 0);
}

void printNumbersWithEvenNumberOfDigits(int array[], int arraySize) {
    for (int i = arraySize - 1; i >= 0; i--) {
        if (hasEvenNumberOfDigits(array[i])) {
            cout << array[i] << endl;
        }
    }
}

void printArrayOfInts(int array) {

}

int main() {

    int mostPopular;
    int arraySize = takeArraySize();
    int array[arraySize];
    int totalDigits = countTotalDigits(array, arraySize);
    int arrayOfDigits[totalDigits];

    fillArray(array, arraySize);

    splitArrayOfIntsToDigits(array, arraySize, arrayOfDigits);

    mostPopular = findMostPopularDigit(arrayOfDigits, totalDigits);

    cout << "Most popular: " << mostPopular << endl;

    cout << "Numbers with even number of digits: " << endl;
    printNumbersWithEvenNumberOfDigits(array, arraySize);

}
