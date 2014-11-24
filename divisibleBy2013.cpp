#include <iostream>

using namespace std;


bool onlyOneDivisibleBy2013(int a, int b) {
    if ((a % 2013 == 0) != (b % 2013 == 0)) {
        return true;
    }
    return false;
}

int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

int main() {
    int a;
    int b;
    a = takeInput("a");
    b = takeInput("b");

    if (onlyOneDivisibleBy2013(a, b)) {
        cout << "да\n";
    } else {
        cout << "не\n";
    }

    return 0;
}
