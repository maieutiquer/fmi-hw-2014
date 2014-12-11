#include <iostream>

using namespace std;


int takeInput(string varName) {
    int input;
    do {
        cout << "Enter " << varName << ":\n";
        cin >> input;
    } while (input < 0);
    return input;
}

void fillArray(int array[], int dimension) {
    for (int i = 0; i < dimension; i++) {
        array[i] = takeInput("array[" + to_string(i) + "]");
    }
}

bool hasConsecutiveSameNumbers(int array[], int dimension) {
    // if no elements, then false
    if (dimension) {
        for (int i = 0; i < dimension - 1; i++) {
            if (array[i] == array[i+1]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int dimension = takeInput("dimension");
    int array[dimension];

    fillArray(array, dimension);

    if (hasConsecutiveSameNumbers(array, dimension)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
