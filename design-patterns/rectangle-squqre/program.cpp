#include <iostream>
#include <typeinfo>
using namespace std;

#include "rectangle.h"
#include "square.h"
using namespace conceptarchitect::shapes;

int main()
{
    Rectangle * rectangles[]={
        new Rectangle(12,3),
        new Square(5),
        new Rectangle(4,8)
    };

    for (auto rectangle : rectangles)
    {
        rectangle->draw();
        cout<<"type:"<<typeid(*rectangle).name()<<endl
            <<"orientation: "<<rectangle->orientation()<<endl
            <<"area: "<<rectangle->area()<<endl
            <<"perimeter: "<<rectangle->perimeter()<<endl
            <<endl;
    }

    Square s(7);
    s.setHeight(5);
    cout<<"My "<<typeid(s).name()<<endl;
    s.draw();
    return 0;
}