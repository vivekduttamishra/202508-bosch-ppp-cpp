#include <iostream>
#include <typeinfo>
using namespace std;

#include "rectangle.h"
#include "square.h"
#include "proper-rectangle.h"
using namespace conceptarchtiect::shapes;

int main()
{
    Rectangle * rectangles[]={
        new ProperRectangle(12,3),
        new Square(5),
        new ProperRectangle(4,8)
    };

    for (auto rectangle : rectangles)
    {
        rectangle->draw();
        cout<<"type:"<<typeid(*rectangle).name()<<endl
            <<"area: "<<rectangle->area()<<endl
            <<"perimeter: "<<rectangle->perimeter()<<endl
            <<endl;
    }

   
    return 0;
}