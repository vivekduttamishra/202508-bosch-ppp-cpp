#pragma once
#include "rectangle.h"
#include<iostream>
using namespace std;

namespace conceptarchtiect::shapes
{
    class Square: public Rectangle
    {
        double side;
        public:
        Square(double side):side(side) {}

        double area(){return side*side;}
        double perimeter(){return 4*side;}
        void draw(){
            cout<<"Square[ "<<side<<"]"<<endl;
        }
    };
}