#pragma once
#include <iostream>
using namespace std;

class StackOverflowException :public exception
{
    public:
    using exception::exception;
};

class StackUnderflowException : public exception
{
    public:
    using exception::exception;
};

template<typename T>
struct Stack
{
    virtual void push(T value)=0;
    virtual T pop()=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
    virtual string str()=0;
};