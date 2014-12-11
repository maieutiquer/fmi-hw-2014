#include <iostream>

using namespace std;


int takeInput(string varName) {
    int input;
    do {
        cout << "Enter " << varName << ":\n";
        cin >> input;

    } while (input < 0 && input > 7);
    return input;
}

bool checkSameLine(int field1[], int field2[]) {
    return (field1[0] == field2[0]) || (field1[1] == field2[1]);
}

int main() {
    int field1[2];
    int field2[2];
    field1[0] = takeInput("field1 position x from 1 to 7");
    field1[1] = takeInput("field1 position y");
    field2[0] = takeInput("field2 position x");
    field2[1] = takeInput("field2 position y");
    if (checkSameLine(field1, field2)) {
        cout << "yes, it can" << endl;
    } else {
        cout << "no, it can't" << endl;
    }
}
