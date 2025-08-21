

#pragma once
#include <vector>
#include <map>
using namespace std;
#include "search-engine.h"

template<typename T>
class CachedSearchEngine:public ISearchEngine<T> 
{
    map<string,Result<T>> cache;
    ISearchEngine<T>* target;
    
public:
    CachedSearchEngine(ISearchEngine<T>* target):target(target) {}

    Result<T> search(string query)
    {
        if (cache.find(query) != cache.end())
        {
            cout<<"LOG: returning resut from the cache"<<endl;
            return cache[query];
        }
        else
        {
            auto result= target->search(query);
            cache[query]=result;
            return result;
        }
    }
};