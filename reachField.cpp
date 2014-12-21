#include <iostream>

using namespace std;


int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

void takePosition(int field[], string message) {

    cout << message << endl;

    do {
        field[0] = takeInput("position x from 1 to 7");
    } while (field[0] < 0 && field[0] > 7);

    do {
        field[1] = takeInput("position y from 1 to 7");
    } while (field[1] < 0 && field[1] > 7);

    cout << endl;

}

bool checkSameLineOrColumn(int field1[], int field2[]) {
    return (field1[0] == field2[0]) || (field1[1] == field2[1]);
}

int main() {

    int field1[2];
    int field2[2];

    takePosition(field1, "Taking field 1 coordinates.");
    takePosition(field2, "Taking field 2 coordinates.");

    if (checkSameLineOrColumn(field1, field2)) {
        cout << "yes, it can" << endl;
    } else {
        cout << "no, it can't" << endl;
    }

}
