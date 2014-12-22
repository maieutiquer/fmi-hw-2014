#include <iostream>
#include <math.h>

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

void fillArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        array[i] = takeInput("array[" + to_string(i) + "]");
    }
}

void insertionSort(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        int j = i;
        while (j > 0 && array[j-1] > array[j]) {
            swap(array[j], array[j-1]);
            j--;
        }
    }
}

void sortHalves(int array[], int arraySize, int arrayWithSortedHalves[]) {

    int firstHalf[arraySize / 2];
    int secondHalf[(int) ceil(arraySize / 2.0)];

    for (int i = 0; i < arraySize / 2; i++) {
        firstHalf[i] = array[i];
    }

    for (int i = 0; i < arraySize / 2; i++) {
        secondHalf[i] = array[(int) ceil(arraySize / 2.0) + i];
    }

    insertionSort(firstHalf, arraySize / 2);
    insertionSort(secondHalf, arraySize / 2);

    for (int i = 0; i < arraySize / 2; i++) {
        arrayWithSortedHalves[i] = firstHalf[i];
    }

    for (int i = 0; i < arraySize / 2; i++) {
        arrayWithSortedHalves[arraySize / 2 + i] = secondHalf[i];
    }

}

void printArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
}

int main() {

    int arraySize = takeArraySize();
    int array[arraySize];
    int sizeAfterSort = arraySize;

    // if odd number of elements, then new size will be lesser by 1
    if (arraySize % 2 != 0) {
        sizeAfterSort--;
    }
    int arrayWithSortedHalves[sizeAfterSort];

    fillArray(array, arraySize);

    cout << "You entered the numbers:" << endl;
    printArray(array, arraySize);
    cout << endl;

    sortHalves(array, arraySize, arrayWithSortedHalves);

    cout << "Array with sorted halves:" << endl;
    printArray(arrayWithSortedHalves, sizeAfterSort);
    cout << endl;

}
