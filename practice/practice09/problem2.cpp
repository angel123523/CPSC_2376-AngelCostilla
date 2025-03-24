#include <iostream>

struct Point {
    float x;
    float y;
};

static Point calcMidpoint(const Point* p1, const Point* p2) {
    float midX = (p1->x + p2->x) / 2.0f;
    float midY = (p1->y + p2->y) / 2.0f;
    return Point{ midX,midY };  
}

int main() {
    // Step 1: Create two points with example coordinates
    Point a{ 1.0f, 2.0f };
    Point b{ 5.0f, 6.0f };

    // Step 2: Call calcMidpoint using pointers to 'a' and 'b'
    Point mid = calcMidpoint(&a,&b);

    // Step 3: Print the midpoint coordinates
    std::cout << "Midpoint is at (" << mid.x << ", " << mid.y << ")" << std::endl; // Should be (3, 4)

    return 0;
}