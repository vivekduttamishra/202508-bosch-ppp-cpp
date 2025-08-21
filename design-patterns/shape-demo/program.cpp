#include <iostream>
using namespace std;
#include "shape.h"
using namespace conceptarchitect::shapes;

int main(){
    Shape * shapes[]={
        new Shape(7), 
        new Shape(7,2),
        new Shape(3,4,5) 
    };

    cout<<"Sizeof(Shape)"<<sizeof(Shape)<<endl;

    for(auto shape : shapes)
    {
        shape->draw();
        cout<<"Area:"<<shape->area()<<endl;
        cout<<"Periemter:"<<shape->perimeter()<<endl;
        cout<<endl;
    }
    return 0;
}