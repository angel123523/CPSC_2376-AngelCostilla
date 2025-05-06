#include "ShapeFactory.h"
#include <fstream>
#include <iostream>
#include <iomanip>

int main() {
    std::ifstream file("shapes.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open shapes.txt\n";
        return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::string originalLine = line;
        auto shape = ShapeFactory::createShape(line);
        if (shape) {
            double a = shape->area();
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Area of " << originalLine << " is " << a << "\n";
        }
        else {
            std::cerr << "Invalid shape definition: " << originalLine << "\n";
        }
    }

    return 0;
}