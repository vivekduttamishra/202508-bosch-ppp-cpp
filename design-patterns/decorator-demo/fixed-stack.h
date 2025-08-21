#pragma once
#include "stack.h"
#include <sstream>
using namespace std;

template<typename T>
class FixedStack:public Stack<T>{
    T * elements;
    int size;
    int top;
    public:
    FixedStack(int size):size(size)
    {
        elements = new T[size];
        top=0;
    }

    void push(T element)
    {
        if(isFull())
            throw StackOverflowException();
        elements[top++] = element;
    }

    T pop()
    {
        if(isEmpty()) throw StackUnderflowException();

        return elements[--top];
    }

    bool isFull() {
        return top==size;
    }

    bool isEmpty() {
        return top==0;
    }

    string str(){
        if(isEmpty()) return "FixedStack(empty)";
        
        stringstream s;
        s<<"FixedStack";
        s<< (isFull()? "[ ":"( ");
        
        for(auto i=top-1;i>=0;i--)
            s<<elements[i]<<" ";

        s<< (isFull()?"] ":") ");
        return s.str();
    }

};

template<typename T>
class PeekableFixedStack:public FixedStack<T> 
{
    public:
    PeekableFixedStack(int size): FixedStack<T>(size){}

    T peek() 
    { 
        T value =this->pop();
        this->push(value);
        return value;
    }
};