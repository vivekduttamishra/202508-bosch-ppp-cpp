#pragma once
#include <iostream>
#include "list.h"
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;

    Node(const T &data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList : public IList<T>
{
private:
    Node<T> *head;
    Node<T> *tail;
    int count;

public:
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~LinkedList()
    {
        clear();
    }
    void add(const T &item) override
    {
        Node<T> *newNode = new Node<T>(item);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    T &operator[](size_t index) override
    {
        if (index >= count)
        {
            throw std::out_of_range("Index out of range");
        }
        Node<T> *current = head;
        for (size_t i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->data;
    }
    int size() const override
    {
        return count;
    }
    void clear() override
    {
        Node<T> *current = head;
        while (current)
        {
            Node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        count = 0;
    }

    // void show() const override
    // {
    //     if (count == 0)
    //     {
    //         cout << "LinkedList(empty)" << endl;
    //         return;
    //     }
    //     cout << "LinkedList: ";
    //     Node<T> *current = head;
    //     while (current)
    //     {
    //         std::cout << current->data << " ";
    //         current = current->next;
    //     }
    //     std::cout << std::endl;
    // }

    // int indexOf(T value)
    // {
    //     int index = 0;
    //     for (auto p = head; p; p = p->next)
    //     {
    //         if (p->data == value)
    //         {
    //             return index;
    //         }
    //         index++;
    //     }
    //     return -1;
    // }

    // double average()
    // {
    //     double sum = 0;
    //     for (auto p = head; p; p = p->next)
    //     {
    //         sum += p->data;
    //     }

    //     return sum / count;
    // }

    // void print()
    // {
    //     for (auto p = head; p; p = p->next)
    //     {
    //         cout << p->data << "\n";
    //     }
    // }

    // LinkedList<T> *searchEvens()
    // {
    //     LinkedList<T> *result = new LinkedList<T>();
    //     for (auto p = head; p; p = p->next)
    //     {
    //         if (p->data % 2 == 0)
    //         {
    //             result->add(p->data);
    //         }
    //         return result;
    //     }
    // }


    template<typename R>
    R execute(ITask<T, R>* task)  {
        task->init();  
        for(auto p = head; p; p = p->next) {
            task->process(p->data);
        }
        return task->end();
    }

};