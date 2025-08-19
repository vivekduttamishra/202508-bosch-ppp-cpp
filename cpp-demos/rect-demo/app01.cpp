#include "rectangle.h"
#include "square.h"

int main(){
    Rectangle* rectangles[]={
        new Rectangle(3.0, 8.0),
        new Square(5.0),
        new Rectangle(15.0, 6.0),
        nullptr
    };

    for(int i=0; rectangles[i] != nullptr; ++i){
    
        rectangles[i]->draw();
        cout << "Area: " << rectangles[i]->area() << endl;
        cout << "Perimeter: " << rectangles[i]->perimeter() << endl;
        cout << "Orientation: "
                  << (rectangles[i]->orientation() == HORIZONTAL ? "HORIZONTAL" : "VERTICAL") << endl;
        cout << endl;
    
    }


    Square square(4.0);
    square.draw();
    square.setWidth(6.0);
    cout<<"My Square "<<endl;
    square.draw();
}