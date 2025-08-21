#include <iostream>
using namespace std;
#include "steel.h"
#include "rubber.h"
#include "steel.h"

using namespace conceptarchitect::ui::core;
using namespace conceptarchitect::ui::steel;
using namespace conceptarchitect::ui::rubber;

Form * createForm(UIFactory * factory)
{
    auto panel1= factory->createPanel();
    panel1->add( factory->createTextBox());
    panel1->add( factory->createTextBox());
    panel1->add( factory->createTextBox() );

    auto panel2= factory->createPanel();
    panel2->add( factory->createButton());
    panel2->add( factory->createButton());
    panel2->add( factory->createButton());

    auto panel3= factory->createPanel();
    panel3->add(panel1);
    panel3->add(panel2);


    auto form= factory->createForm();
    form->add(panel3);
    form->add(factory->createButton());

    return form;
}

int main()
{
    //auto factory= new SteelUIFactory();
    auto factory=new RubberUIFactory();
    auto ui = createForm(factory);

    ui->draw();
}
