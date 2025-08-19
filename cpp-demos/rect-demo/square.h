#pragma once
#include "rectangle.h"

class Square : public Rectangle {
    Orientation orientation() const override {
        return HORIZONTAL; // A square is always considered horizontal for simplicity
    }
    public:
        Square(double side) : Rectangle(side, side) {}
};