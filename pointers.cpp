#include <iostream>

int main() {
    int x = 10;
    int *p = &x;

    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << p << std::endl;

    return 0;
}


#include <cmath>

// Function to calculate area of a square
double calculateArea(double side) {
    return side * side;
}

// Function to calculate area of a rectangle
double calculateArea(double length, double width) {
    return length * width;
}

// Function to calculate area of a circle
double calculateArea(double radius) {
    return M_PI * radius * radius;
}

void calculateAndPrintAreas() {
    double side = 5.0;
    double length = 4.0;
    double width = 3.0;
    double radius = 2.5;

    // Calculating and printing areas
    std::cout << "Area of square: " << calculateArea(side) << std::endl;
    std::cout << "Area of rectangle: " << calculateArea(length, width) << std::endl;
    std::cout << "Area of circle: " << calculateArea(radius) << std::endl;
}
