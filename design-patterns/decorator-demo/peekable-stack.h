#pragma once
#include "stack.h"

template<typename T>
class PeekableStack: public Stack<T>
{
    Stack<T> &stack;
    public:
    PeekableStack(Stack<T> &stack) : stack(stack){}

    void push(T value) { stack.push(value); }
    T pop() { return stack.pop(); }
    bool isEmpty() { return stack.isEmpty(); }
    bool isFull() { return stack.isFull(); }
    string str() { return string("Peekable -> ")+stack.str(); }

    T peek()
    {
        T value=this->pop();
        this->push(value);
        return value;
    }

};