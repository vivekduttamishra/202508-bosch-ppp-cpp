#include <iostream>
#include <typeinfo>
using namespace std;


class Bird;
class Egg{
    public:
        virtual Bird* hatch()=0;
};

class Bird{
    public:
        virtual Egg* layEgg()=0;
};






class Crow:public Bird{

    public:
        Egg* layEgg(); 
};

class Parrot:public Bird{

    public:
        Egg* layEgg(); 

};

class CrowEgg : public Egg {
    public:
        Bird* hatch() override {
            return new Crow();
        }
};

class ParrotEgg : public Egg {
    public:
        Bird* hatch() override {
            return new Parrot();
        }
};

Egg* Crow::layEgg() {
    return new CrowEgg();
}
Egg* Parrot::layEgg() {
    return new ParrotEgg();
}



void identifyBird(Bird* bird) {
    cout<< typeid(*bird).name() << endl; 
}

int main(){

    Crow crow;
    Parrot parrot;

    Bird * baby1= crow.layEgg()->hatch();
    Bird * baby2= parrot.layEgg()->hatch();

    identifyBird(baby1);
    identifyBird(baby2);

    return 0;
}

