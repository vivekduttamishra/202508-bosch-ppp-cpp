#include <iostream>
#include "list.h"
#include "linkedlist.h"
#include "darray.h"
using namespace std;

void testList(IList<int>* list) {
    list->add(1);
    list->add(2);
    list->add(3);

    for(int i = 0; i < list->size(); ++i) {
        cout << (*list)[i] << "\n";
    }

    list->show();
    cout<<"-------------------"<<endl<<endl;

}


int main() {

    IList<int>* list1 = new LinkedList<int>();
    
    cout<<"Testing LinkedList"<<endl;
    testList(list1);


    cout<<"Testing DArray"<<endl;
    IList<int>* list2 = new DArray<int>();
    testList(list2);

}