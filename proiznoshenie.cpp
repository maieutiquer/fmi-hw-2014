#include <iostream>

using namespace std;

int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

string pronounce(int number) {
    string numberAsString = to_string(number);
    string pronunciation = "";
    string space = " ";
    string numbersAsWords[10] = {
        "нула", "едно", "две",
        "три", "четири", "пет",
        "шест", "седем", "осем",
        "девет",
    };
    string error = "грешка"; // TODO: exception handling
    int digitsCount = numberAsString.size();
    int rest;
    if (digitsCount == 4) {
        pronunciation += "хиляда";
        return pronunciation;
    } else if (digitsCount == 3) {
        switch (numberAsString[0] - '0') {
            case 1:
                pronunciation += "сто" + space;
                break;
            case 2:
            case 3:
                pronunciation += numbersAsWords[numberAsString[0] - '0']
                    + "ста" + space;
                break;
            default:
                pronunciation += numbersAsWords[numberAsString[0] - '0']
                    + "стотин" + space;
                break;
        }
        rest = number % 100;
        if (rest != 0) {
            if (number % 10 == 0 || rest < 20) {
                pronunciation += "и" + space;
            }
            pronunciation += pronounce(rest);
        }
    } else if (digitsCount == 2) {
        if (number >= 20) {
            switch (numberAsString[0] - '0') {
                case 2:
                    pronunciation += "двадесет" + space;
                    break;
                default:
                    pronunciation += numbersAsWords[numberAsString[0] - '0']
                        + "десет" + space;
                    break;
            }
            rest = number % 10;
            if (rest != 0) {
                pronunciation += "и" + space;
                pronunciation += pronounce(rest);
            }
        } else {
            switch (numberAsString[1] - '0') {
                case 0:
                    pronunciation += "десет" + space;
                    break;
                case 1:
                    pronunciation += "единадесет" + space;
                    break;
                case 2:
                    pronunciation += "дванадесет" + space;
                    break;
                default:
                    pronunciation += numbersAsWords[numberAsString[1] - '0']
                        + "надесет" + space;
                    break;
            }
        }
    } else if (digitsCount == 1) {
        pronunciation += numbersAsWords[numberAsString[0] - '0'] + space;
    }
    return pronunciation;
}

int main() {
    int number;
    do {
        number = takeInput("number");
    } while (number < 0 || number > 1000);

    string pronunciation = pronounce(number);

    cout << pronunciation << endl;
}
