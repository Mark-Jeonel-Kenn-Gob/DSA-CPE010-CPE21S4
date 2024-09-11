#include <iostream>
using namespace std;

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;

public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();
};

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}

int main() {
    Triangle set1(40, 30, 110);
    // Check if the created triangle is valid
    if (set1.validateTriangle()) {
        cout << "The shape is a valid triangle." << endl;
    } else {
        cout << "The shape is NOT a valid triangle." << endl;
    }
    return 0;
}

/*
(Method Definition is already included in the Class
Declaration and Method Definition Section.)
*/
