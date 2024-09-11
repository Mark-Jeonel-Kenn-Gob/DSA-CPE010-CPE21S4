#include <iostream>
#include <cmath>  // For sqrt() and pow()

using namespace std;

class Triangle {
private:
    double angleA, angleB, angleC; // Angles of the triangle
    double sideA, sideB, sideC;    // Sides of the triangle
    double totalAngle;

public:
    Triangle(double A, double B, double C, double a, double b, double c);
    void setAngles(double A, double B, double C);
    void setSides(double a, double b, double c);
    const bool validateTriangle();
    double calculateArea();       
    double calculatePerimeter();
    string determineTriangleType(); 
};

Triangle::Triangle(double A, double B, double C, double a, double b, double c) {
    angleA = A;
    angleB = B;
    angleC = C;
    sideA = a;
    sideB = b;
    sideC = c;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setSides(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

const bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}

double Triangle::calculateArea() {
    if (!validateTriangle()) {
        cout << "Invalid triangle. Cannot calculate area.\n";
        return 0;
    }
    double s = (sideA + sideB + sideC) / 2;
    double area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    return area;
}

double Triangle::calculatePerimeter() {
    return sideA + sideB + sideC;
}

string Triangle::determineTriangleType() {
    if (!validateTriangle()) {
        return "Invalid triangle";
    }

    if (angleA < 90 && angleB < 90 && angleC < 90) {
        return "Acute-angled triangle";
    } else if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "Obtuse-angled triangle";
    } else if (angleA == 90 || angleB == 90 || angleC == 90) {
        return "Right-angled triangle";
    } else {
        return "Others";
    }
}

int main() {
    Triangle set1(40, 30, 110, 3, 4, 5);

    if (set1.validateTriangle()) {
        cout << "The shape is a valid triangle.\n";
    } else {
        cout << "The shape is NOT a valid triangle.\n";
    }

    double area = set1.calculateArea();
    cout << "Area of the triangle: " << area << endl;

    double perimeter = set1.calculatePerimeter();
    cout << "Perimeter of the triangle: " << perimeter << endl;

    string type = set1.determineTriangleType();
    cout << "The triangle is: " << type << endl;

    return 0;
}
