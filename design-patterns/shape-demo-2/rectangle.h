#pragma once
#include "shape.h"
namespace conceptarchitect::shapes
{
    class Rectangle :public Shape
    {
        double width, height;

    public:
        Rectangle(double width, double height)
        {
            this->width = width;
            this->height = height;
        }
        double perimeter()
        {
            double p = 0;
            p = 2 * (width + height);
            return p;
        }

        double area()
        {
            double a = 0;
            a = width * height;
            return a;
        }

        void draw()
        {
            cout << "Rectangle[" << width << "," << height << "]" << endl;
        }
    };
}