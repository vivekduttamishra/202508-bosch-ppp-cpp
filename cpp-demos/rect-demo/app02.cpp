#include "rectangle.h"
#include "square.h"
#include "shape.h"

int main(){
    Rectangle* rectangles[]={
        new ProperRectangle(3.0, 8.0),
        new RectSquare(5.0),
        new Square(4),
        new ProperRectangle(15.0, 6.0),
        nullptr
    };

    for(int i=0; rectangles[i] != nullptr; ++i){
    
        rectangles[i]->draw();
        cout << "Area: " << rectangles[i]->area() << endl;
        cout << "Perimeter: " << rectangles[i]->perimeter() << endl;
        // cout << "Orientation: "
        //           << (rectangles[i]->orientation() == HORIZONTAL ? "HORIZONTAL" : "VERTICAL") << endl;
        cout << endl;
    
    }


    Square square(4.0);
    square.draw();
    //square.setWidth(6.0);
    cout<<"My Square "<<endl;
    square.draw();

    cout<<"Size of Square: " << sizeof(Square) << endl;
    cout<<"Size of Rectangle: " << sizeof(ProperRectangle) << endl;
    cout<<"Size of RectSquare: " << sizeof(RectSquare) << endl;
}