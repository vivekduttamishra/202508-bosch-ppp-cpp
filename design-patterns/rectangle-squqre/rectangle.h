#pragma once
#include <iostream>
using namespace std;

namespace conceptarchitect::shapes
{
    class Rectangle 
    {
        double width, height;

    public:
        Rectangle(double width, double height)
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