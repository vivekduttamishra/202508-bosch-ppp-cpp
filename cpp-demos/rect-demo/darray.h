#include <iostream>
#include "list.h"
using namespace std;


template<typename T>
class DArray : public IList<T> {
private:
    T* data;
    size_t capacity;
    size_t count;
public:
    DArray(size_t initialCapacity = 10) : capacity(initialCapacity), count(0) {
        data = new T[capacity];
    }
    ~DArray() {
        delete[] data;
    }
    void add(const T& item) override {
        if (count >= capacity) {
            capacity *= 2; 
            T* newData = new T[capacity];
            for (size_t i = 0; i < count; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[count++] = item;
    }
    T& operator[](size_t index) override {
        if (index >= count) {
            throw std::out_of_range("Index out of range");
        }   
        return data[index];

    }
    int size() const override {
        return count;
    }   
    void clear() override {
        delete[] data;
        data = new T[capacity];
        count = 0;
    }
    void show() const override {
        if(count == 0) {
            cout << "DArray(empty)" << endl;
            return;
        }
        cout << "DArray: ";
        for (size_t i = 0; i < count; ++i) {
            cout << data[i] << " ";
        }   
        cout << endl;
    }
       
};