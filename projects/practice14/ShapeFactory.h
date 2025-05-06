#pragma once
#include "Shape.h"
#include "Shapes.h"
#include <memory>
#include <sstream>
#include <string>

class ShapeFactory {
public:
    static std::shared_ptr<Shape> createShape(const std::string& line) 
    {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "circle") {
            double r;
            if (iss >> r)
                return std::make_shared<Circle>(r);
        }
        else if (type == "square") {
            double s;
            if (iss >> s)
                return std::make_shared<Square>(s);
        }
        else if (type == "rectangle") {
            double w, h;
            if (iss >> w >> h)
                return std::make_shared<Rectangle>(w, h);
        }
     
        return nullptr; 
    }
};