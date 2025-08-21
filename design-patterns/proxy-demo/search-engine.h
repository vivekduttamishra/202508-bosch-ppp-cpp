#pragma once
#include <vector>
using namespace std;

template<typename T>
struct Result
{
    vector<T*> values;
    string error;
};

template<typename T>
class ISearchEngine
{
    public:
    virtual Result<T> search(string query)=0;
};