#pragma once
#include <iostream>
#include "rectangle.h"
using namespace std;

namespace conceptarchtiect::shapes
{
    class ProperRectangle : public Rectangle
    {
        double width, height;

    public:
        ProperRectangle(double width, double height)
        {
            this->width = width;
            this->height = height;
        }
        virtual double perimeter()
        {
            double p = 0;
            p = 2 * (width + height);
            return p;
        }

        virtual double area()
        {
            double a = 0;
            a = width * height;
            return a;
        }

        virtual void draw()
        {
            cout << "Rectangle[" << width << "," << height << "]" << endl;
        }

        void setWidth(double width){
            this->width = width;
        }

        void setHeight(double height){
            this->height = height;
        }

        virtual string orientation(){
            if (width>height) 
                return "SLEEPING";
            else 
                return "STANDING"; 
        }
    };
}