#include <iostream>

using namespace std;


int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

int takeDimension() {
    int dimension;
    do {
        dimension = takeInput("dimension");
    } while (dimension < 10 || dimension > 20);
    return dimension;
}

void fillArray(int array[], int dimension) {
    for (int i = 0; i < dimension; i++) {
        array[i] = takeInput("array[" + to_string(i) + "]");
    }
}

int countOccurences(int number, int array[], int dimension) {
    int counter = 0;
    for (int i = 0; i < dimension; i++) {
        if (array[i] == number) {
            counter++;
        }
    }
    return counter;
}

// TODO: if equally most popular, then return least value
int findMostPopular(int array[], int dimension) {
    int mostPopular = 0;
    int mostOccurences = 0;
    int alreadyCheckedNumbers[dimension];
    for (int i = 0; i < dimension; i++) {
        bool isAlreadyChecked = countOccurences(array[i], alreadyCheckedNumbers, dimension);
        if (!isAlreadyChecked) {
            int occurences = countOccurences(array[i], array, dimension);
            if (occurences > mostOccurences) {
                mostOccurences = occurences;
                mostPopular = array[i];
            } else if (occurences == mostOccurences && array[i] < mostPopular) {
                mostPopular = array[i];
            }
            alreadyCheckedNumbers[i] = array[i];
        }
    }
    return mostPopular;
}

int main() {
    int mostPopular;
    int dimension = takeDimension();
    int array[dimension];

    fillArray(array, dimension);

    mostPopular = findMostPopular(array, dimension);

    cout << mostPopular << endl;
}
