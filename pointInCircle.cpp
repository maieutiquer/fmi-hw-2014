#include <iostream>

using namespace std;


int takeInput(string varName) {
    int input;
    cout << "Enter " << varName << ":\n";
    cin >> input;
    return input;
}

double square(double x) {
    return x*x;
}

bool isInCircle(double pointX, double pointY,
        double centerX, double centerY, double radius) {
    return square(pointX - centerX) + square(pointY - centerY) <= square(radius);
}

int main() {

    int pointX;
    int pointY;
    int circlesCenterX = 4;
    int circlesCenterY = -2;
    double circle1Radius = 4;
    double circle2Radius = 2;
    double circle3Radius = 1;

    pointX = takeInput("point X");
    pointY = takeInput("point Y");
    bool pointInFigure = (pointY <= -2
            &&  isInCircle(pointX, pointY, circlesCenterX, circlesCenterY, circle1Radius))
            || (isInCircle(pointX, pointY, circlesCenterX, circlesCenterY, circle2Radius)
            && !isInCircle(pointX, pointY, circlesCenterX, circlesCenterY, circle3Radius));

    if (pointInFigure) {
        cout << "Yes, it's inside!" << endl;
    } else {
        cout << "No, it's not inside..." << endl;
    }

}
