#pragma once
#include <string>
#include "search-engine.h"
using namespace std;
class Authenticator
{
    string user;
    Authenticator(){
        user="";
    }

    public:
    static Authenticator * instance(){
        static Authenticator * _instance=new Authenticator();
        return _instance;
    }

    bool authenticate(string username,string password)
    {
        if(username.size()==password.size() && username!=password){
            user=username;
            return true;
        }
        else
        {
            return false;
        }
    }

    void logout(){user="";}

    bool isAuthenticated(){return !user.empty();}
};

template<class E>
class AuthenticatedSearchEngine : public ISearchEngine<E>
{
    ISearchEngine<E> *target;
    public:
    AuthenticatedSearchEngine(ISearchEngine<E> *target)
    {
        this->target=target;
    }

    Result<E> search(string query) override
    {
        if(!Authenticator::instance()->isAuthenticated())
        {
            Result<E> result;
            result.error="Authentication failed";
            return result;
        }
        else
            return target->search(query);
    }


};

