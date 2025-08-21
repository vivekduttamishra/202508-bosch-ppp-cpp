#include <iostream>
using namespace std;
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
using namespace conceptarchitect::shapes;
using namespace bosch::designs;

int main(){
    Shape * shapes[]={
        new Circle(7), 
        new Rectangle(7,2),
        new Triangle(3,4,5) 
    };

    cout<<"sizeof(Shape)="<<sizeof(Shape)<<endl;
    cout<<"sizeof(Circle)="<<sizeof(Circle)<<endl;
    cout<<"sizeof(Rectangle)="<<sizeof(Rectangle)<<endl;
    cout<<"sizeof(Triangle)="<<sizeof(Triangle)<<endl;


    for(auto shape : shapes)
    {
        shape->draw();
        cout<<"Area:"<<shape->area()<<endl;
        cout<<"Periemter:"<<shape->perimeter()<<endl;
        cout<<endl;
    }
    return 0;
}