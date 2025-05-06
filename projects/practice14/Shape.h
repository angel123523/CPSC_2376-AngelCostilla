#pragma once
#include <memory>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};
