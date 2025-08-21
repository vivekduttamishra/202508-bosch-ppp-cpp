#include <iostream>
using namespace std;

#include "stack.h"
#include "fixed-stack.h"
#include "linked-stack.h"
#include "peekable-stack.h"

void TestPush(Stack<int> &stack, int push_count)
{
    try
    {

        for (int i = 0; i < push_count; i++)
        {
            cout << "trying to push " << i;
            stack.push(i);
            cout << "done\t" << stack.str() << endl;
        }
    }
    catch (StackOverflowException &e)
    {
        std::cerr << "Stack Overflow" << '\n';
    }
}

void TestPop(Stack<int> &stack, int pop_count)
{
    try
    {
        for(int i = 0; i < pop_count; i++)
        {
            cout<<"trying to pop ";
            auto value= stack.pop();
            cout<<value<<"\t"<<stack.str()<<endl;
        }
    }
    catch(StackUnderflowException &e)
    {
        cout<<"ERROR: Stack is Empty"<<endl;
    }
}

void TestStack(Stack<int> &stack, int push_count, int pop_count)
{
    TestPush(stack, push_count);
    TestPop(stack, pop_count);
    while(!stack.isEmpty())
    {
        cout<<"flushing "<<stack.pop()<<endl;
        if(!stack.isEmpty())
        {
            PeekableStack<int> *ps = dynamic_cast<PeekableStack<int>*>(&stack);
            if(ps!=nullptr)
                cout<<"\tnext item is "<<ps->peek()<<endl;
        }
    }
}

int main()
{
    Stack<int>* stack=new FixedStack<int>(10);

    stack= new PeekableStack<int>(*stack);

    

    TestStack(*stack,20,5);

    return 0;
}