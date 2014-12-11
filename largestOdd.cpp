#include <iostream>
#include <climits>

using namespace std;


int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

int fillArray(int array[]) {
    int counter = 0;
    int currentInput = -1; // initialize with something different than 0
    while (currentInput != 0) {
        currentInput = takeInput("array[" + to_string(counter) + "]");
        if (currentInput != 0) {
            array[counter] = currentInput;
            counter++;
        }
    }
    return counter; // return array dimension to work with
}

bool isOdd(int number) {
    if (number % 2 != 0) {
        return true;
    }
    return false;
}

int findLargestOddNumber(int array[], int dimension) {
    int largestOddNumber = INT_MIN;
    for (int i = 0; i < dimension; i++) {
        if (isOdd(array[i]) && array[i] > largestOddNumber) {
            largestOddNumber = array[i];
        }
    }
    if (largestOddNumber == INT_MIN) {
        return 0;
    }
    return largestOddNumber;
}

int main() {
    int array[1000];
    int dimension = fillArray(array);
    cout << "You entered " << dimension << " numbers." << endl;

    int largestOddNumber = findLargestOddNumber(array, dimension);

    if (largestOddNumber) {
        cout << "Largest odd number is " << largestOddNumber << endl;
    } else {
        cout << "You entered no odd numbers." << endl;
    }
}
