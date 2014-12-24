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

int getSumOfTopAndBottomTriangles(int matrixSize, void *matrixArg) {
    int (*matrix)[matrixSize] = (int (*)[matrixSize]) matrixArg;
    int sum = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (i < j && j < matrixSize - 1 - i ||
                    i > matrixSize - 1 - j && j < i) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int getSumOfDiagonalAboveMain(int matrixSize, void *matrixArg) {
    int (*matrix)[matrixSize] = (int (*)[matrixSize]) matrixArg;
    int sum = 0;

    for (int i = 0; i < matrixSize - 1; i++) {
        sum += matrix[i][i + 1];
    }
    return sum;
}

int getProductOfDiagonalBelowSec(int matrixSize, void *matrixArg) {
    int (*matrix)[matrixSize] = (int (*)[matrixSize]) matrixArg;
    int product = 1;

    for (int i = 0; i < matrixSize - 1; i++) {
        product *= matrix[i + 1][matrixSize - 1 - i];
    }
    return product;
}

int main() {

    int matrixSize;
    int sumOfTopAndBottomTriangles;
    int sumOfDiagonalAboveMain;
    int productOfDiagonalBelowSec;

    do {
        matrixSize = takeInput("3 <= n <= 20");
    } while (matrixSize < 3 || matrixSize > 20);

    int squareMatrix[matrixSize][matrixSize];

    fillSquareMatrix(matrixSize, squareMatrix);
    cout << "Your matrix is:" << endl;
    printSquareMatrix(matrixSize, squareMatrix);

    sumOfTopAndBottomTriangles = getSumOfTopAndBottomTriangles(matrixSize, squareMatrix);
    cout << "The sum of elements in top and bottom triangles: "
            << sumOfTopAndBottomTriangles << endl;

    sumOfDiagonalAboveMain = getSumOfDiagonalAboveMain(matrixSize, squareMatrix);
    cout << "The sum of elements in diagonal above main: "
            << sumOfDiagonalAboveMain << endl;

    productOfDiagonalBelowSec = getProductOfDiagonalBelowSec(matrixSize, squareMatrix);
    cout << "The sum of elements in diagonal below secondary: "
            << productOfDiagonalBelowSec << endl;

}
