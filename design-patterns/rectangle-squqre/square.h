#pragma once
#include "rectangle.h"

namespace conceptarchitect::shapes
{
    class Square: public Rectangle
    {
        public:
        Square(double side):Rectangle(side,side) {}
    };
}