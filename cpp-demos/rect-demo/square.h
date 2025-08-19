#pragma once
#include "rectangle.h"

class RectSquare : public ProperRectangle {
    Orientation orientation() const override {
        throw runtime_error("RectSquare does not have a defined orientation.");
    }
    public:
        RectSquare(double side) : ProperRectangle(side, side) {}
};


class Square : public Rectangle {
    private:
        double side;
    public:
        Square(double s) : side(s) {}
        double area() const {
            return side * side;
        }
        double perimeter() const {
            return 4 * side;
        }
        void draw() {
            cout << "Drawing square with side: " << side << endl;
        }
};

