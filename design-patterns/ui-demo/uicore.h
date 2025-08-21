#pragma once
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

namespace conceptarchitect::ui::core{

    class Component{
        public:
        virtual string name()=0;

        virtual void draw(int indent=0)
        {
            for(int i=0; i<indent; i++)
                cout<<"\t";
            cout<<name()<<" drawn"<<endl;
        }
    };

    class Container:public Component{
        vector<Component*> components;
        public:
        virtual void add(Component* component)
        {
            components.push_back(component);
        }

        void draw(int indent=0)
        {
            Component::draw(indent);
            for(auto component : components)
                component->draw(indent+1);
        }
        
    };

    class Form:public Container
    {
        public:
       
    };
    class Panel: public Container
    {
        public:
        
    };

    class Button:public Component
    {
        public:
    };

    class TextBox:public Component
    {

    };

    class UIFactory
    {
        public:
        virtual Form * createForm()=0;
        virtual Panel * createPanel()=0;
        virtual TextBox * createTextBox()=0;
        virtual Button * createButton()=0;
    };



}