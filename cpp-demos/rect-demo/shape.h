#pragma once


class Rectangle{
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;   
        virtual void draw() = 0;
};