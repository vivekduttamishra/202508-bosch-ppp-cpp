#pragma once
#include <iostream>
#include "uicore.h"
using namespace std;
using namespace conceptarchitect::ui::core;

namespace conceptarchitect::ui::rubber{

    class RubberForm:public Form
    {
        
       public:
        string name(){return "RubberForm";}
    };

    class RubberButton:public Button
    {
        public:
        string name(){return "RubberButton";}
    };

    class RubberTextBox:public TextBox
    {
        public:
        string name(){return "RubberTextBox";}
    };

    class RubberPanel:public Panel
    {
        public:
        public:
        string name(){return "RubberPanel";}
    };

    class RubberUIFactory:public UIFactory
    {
        public:
        Form * createForm(){return new RubberForm();}
        Panel * createPanel(){return new RubberPanel();}
        TextBox * createTextBox(){return new RubberTextBox();}
        Button * createButton(){return new RubberButton();}

    };

}