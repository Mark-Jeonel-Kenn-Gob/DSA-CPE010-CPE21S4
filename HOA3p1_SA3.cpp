#include <iostream>
#include <cmath>
using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2;

    cout << "Enter x1, y1 (first point): ";
    cin >> x1 >> y1;
    cout << "Enter x2, y2 (second point): ";
    cin >> x2 >> y2;

    cout << "Distance between the two points: " << calculateDistance(x1, y1, x2, y2) << endl;

    return 0;
}