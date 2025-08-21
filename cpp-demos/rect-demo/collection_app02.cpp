#include <iostream>
#include <string>
#include "list.h"
#include "linkedlist.h"
#include "darray.h"
using namespace std;



//fill a given number of elements to list list
template<typename X, typename... T>
void fillList(IList<X>* list, T... items) {

    (list->add(items), ...); // C++17 fold expression to add all items
}

template<typename T>
void printList(string prompt, IList<T>* list) {
    cout<< prompt << ": ";
    for (int i = 0; i < list->size(); ++i) {
        cout << list->operator[](i) << " ";
    }
    cout << endl;
    
}

struct AverageTask : public ITask<int, double> {

    double sum;
    int count;
    void init() override {
        sum = 0;
        count = 0;
    }

    void process(int input) override {
        sum += input;
        count++;
    }

    double end() override {
        return count > 0 ? sum / count : 0.0;
    }


};

struct IndexFinder: public ITask<int, int> {
    int value;
    int index;
    bool found=false;
    IndexFinder(int v) : value(v) {}


    void init() override {
        index = 0;
        found=false;
    }

    void process(int input) override {
        if(!found){
            if(input==value){
                found=true;
            } else{
                index++;
            }
        }
    }

    int end() override {
        if(!found) {
            return -1; // not found
        }
       return index; 
    }





int main() {

    LinkedList<int> *list=new LinkedList<int>();

    fillList(list, 1,2,9,11,8,7,6);

    printList("LinkedList", list);
 
    auto average= list->execute(new AverageTask());

    cout<< "Average: " << average << endl;

    int testFor[]={2,11,20, 7};

    for(auto v: testFor) {
        auto index = list->execute(new IndexFinder(v));
        cout<<"index of " << v << ": " << index << endl;
    }

}