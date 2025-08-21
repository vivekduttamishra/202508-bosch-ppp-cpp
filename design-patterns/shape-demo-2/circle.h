#pragma once
#define PI 3.141592653589793
#include "shape.h"
namespace conceptarchitect::shapes
{
    class Circle:public Shape
    {
        double radius;

    public:
        Circle(double radius)
        {
            this->radius = radius;
        }
        double perimeter()
        {
            double p = 0;
            p = 2 * PI * radius;
            return p;
        }

        double area()
        {
            double a = 0;
            a = PI * radius * radius;
            return a;
        }

        void draw()
        {
            cout << "Circle(" << radius << ")" << endl;
        }
    };
}