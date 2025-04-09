#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>

class Shape {
public:
    virtual ~Shape() = default;  
    virtual double getArea() const = 0;  
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

std::vector<std::unique_ptr<Shape>> readShapesFromFile(const std::string& filename) {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string shapeType;
        ss >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            ss >> width >> height;
            shapes.push_back(std::make_unique<Rectangle>(width, height));
        }
        else if (shapeType == "circle") {
            double radius;
            ss >> radius;
            shapes.push_back(std::make_unique<Circle>(radius));
        }
    }
    return shapes;
}
int main() {
    std::string filename = "shapes.txt";
    std::vector<std::unique_ptr<Shape>> shapes = readShapesFromFile(filename);
    printAllAreas(shapes);

    return 0;
}
