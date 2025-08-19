#include <iostream>
using namespace std;


class Egg{
    public:
        void hatch(){
            cout << "Egg is hatching!" << endl;
        }
};

class Bird{
    public:
        Egg layEgg(){
            return Egg();
        }
};

class Crow:public Bird{

};

class Parrot:public Bird{
};

int main(){

    Crow crow;
    Parrot parrot;

    crow.layEgg().hatch();
    parrot.layEgg().hatch();

    return 0;
}

