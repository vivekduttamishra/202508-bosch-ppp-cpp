#pragma once
#include "stack.h"
#include <sstream>
using namespace std;



template<typename T>
class LinkedStack:public Stack<T>{
    struct Node 
    {
        T value;
        Node * next;
        Node * previous;
    };

    Node * top=nullptr;
    
    public:
    

    void push(T element)
    {
       
        auto node = new Node{element, top};
        top=node;
    }

    T pop()
    {
        if(isEmpty()) throw StackUnderflowException();

        auto node=top;
        top=top->next;
        auto value= node->value;
        delete node;
        return value;
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return top==nullptr;
    }

    string str(){
        if(isEmpty()) return "FixedStack(empty)";
        
        stringstream s;
        s<<"FixedStack";
        s<< "( ";
        
        for(auto n=top;n; n=n->next)
            s<<n->value<<" ";

        s<< ") ";
        return s.str();
    }

};

template<typename T>
class PeekableLinkedStack: public LinkedStack<T>
{
    public:
    T peek()
    {
        T value=this->pop();
        this->push(value);
        return value;
    }
};