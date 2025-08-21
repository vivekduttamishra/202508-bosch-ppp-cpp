#pragma once
#include "shape.h"
#include <math.h>
#include <iostream>
using namespace std;

namespace bosch::designs
{

    class Triangle : public Shape

    {
        double s1, s2, s3;

    public:
        Triangle(double s1, double s2, double s3)
        {
            this->s1 = s1;
            this->s2 = s2;
            this->s3 = s3;
        }

        double perimeter()
        {
            return s1 + s2 + s3;
        }

        double area()
        {
            double s = perimeter() / 2;
            double a = sqrt(s * (s - s1) * (s - s2) * (s - s2));
            return a;
        }

        void draw()
        {
            cout << "Triangle<" << s1 << "," << s2 << "," << s3 << ">" << endl;
        }
    };
}