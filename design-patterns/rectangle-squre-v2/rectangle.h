#pragma once

namespace conceptarchtiect::shapes
{
    class Rectangle
    {
        public:
        virtual double area()=0;
        virtual double perimeter()=0;
        virtual void draw()=0;

    };
}