#pragma once
#include <iostream>
#include "uicore.h"
using namespace std;
using namespace conceptarchitect::ui::core;

namespace conceptarchitect::ui::steel{

    class SteelForm:public Form
    {
        public:
        string name(){return "SteelForm";}
    };

    class SteelButton:public Button
    {
        public:
        string name(){return "SteelButton";}
    };

    class SteelTextBox:public TextBox
    {
        public:
            string name(){return "SteelTextBox";}
    };

    class SteelPanel:public Panel
    {
       public:
        string name(){return "SteelPanel";}
    };

    class SteelUIFactory:public UIFactory
    {
        public:
        Form * createForm(){return new SteelForm();}
        Panel* createPanel(){return new SteelPanel();}
        TextBox * createTextBox(){return new SteelTextBox();}
        Button * createButton(){return new SteelButton();}

    };

}