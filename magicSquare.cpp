#include <iostream>

using namespace std;


int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

void fillSquareMatrix(int matrixSize, void *matrixArg) {
    int (*matrix)[matrixSize] = (int (*)[matrixSize]) matrixArg;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrix[i][j] = takeInput("matrix[" + to_string(i) + "][" + to_string(j) + "]");
        }
    }
}

void printSquareMatrix(int matrixSize, void *matrixArg) {
    int (*matrix)[matrixSize] = (int (*)[matrixSize]) matrixArg;

    for (int i = 0; i < matrixSize; i++) {
        cout << "[ ";
        for (int j = 0; j < matrixSize; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "]\n";
    }
}

int getSumOfArrayElements(int array[], int arraySize) {
    int sum = 0;
    for (int i = 0; i < arraySize; i++) {
        sum += array[i];
    }
    return sum;
}

int getSumOfMatrixColElements(int matrixSize, void *matrixArg, int column) {
    int (*matrix)[matrixSize] = (int (*)[matrixSize]) matrixArg;
    int sum = 0;
    for (int i = 0; i < matrixSize; i++) {
        sum += matrix[i][column];
    }
    return sum;
}

bool isMagicSquare(int matrixSize, void *matrixArg) {
    int (*matrix)[matrixSize] = (int (*)[matrixSize]) matrixArg;

    // get the sum of all elements from the first row
    int sumOfFirstRowElements = getSumOfArrayElements(matrix[0], matrixSize);
    // and from the first column
    int sumOfFirstColElements = getSumOfMatrixColElements(matrixSize, matrix, 0);
    // then compare them
    if (sumOfFirstRowElements != sumOfFirstColElements) {
        return false;
    }

    // start iterating from second row and column
    for (int i = 1; i < matrixSize; i++) {
        int sumOfRowElements = getSumOfArrayElements(matrix[i], matrixSize);
        if (sumOfRowElements != sumOfFirstRowElements) {
            return false;
        }
        // if row i is OK, then compare column i
        int sumOfColElements = getSumOfMatrixColElements(matrixSize, matrix, i);
        if (sumOfColElements != sumOfFirstColElements) {
            return false;
        }
    }
    return true;
}

int main() {

    int matrixSize;

    do {
        matrixSize = takeInput("1 <= n <= 20");
    } while (matrixSize < 1 || matrixSize > 20);

    int squareMatrix[matrixSize][matrixSize];

    fillSquareMatrix(matrixSize, squareMatrix);
    cout << "Your matrix is:" << endl;
    printSquareMatrix(matrixSize, squareMatrix);

    if (isMagicSquare(matrixSize, squareMatrix)) {
        cout << "You're a wizard, User.\n";
    } else {
        cout << "No, it's not a magic square.\n";
    }

}
