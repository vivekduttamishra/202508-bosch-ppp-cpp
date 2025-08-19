#pragma once
#include <iostream>

using namespace std;

enum Orientation {
    HORIZONTAL,
    VERTICAL
};

class Rectangle{
    private:
        double width;
        double height;
        public:
        Rectangle(double w, double h) : width(w), height(h) {}
        double area() const {
            return width * height;
        }
        double perimeter() const {
            return 2 * (width + height);
        }
        void draw(){
            cout << "Drawing rectangle with width: " << width
                << " and height: " << height << endl;
        }
        virtual Orientation orientation() const {
            return (width > height) ? HORIZONTAL : VERTICAL;
        }

        void setWidth(double w) {
            width = w;
        }

        void setHeight(double h) {
            height = h;
        }
};