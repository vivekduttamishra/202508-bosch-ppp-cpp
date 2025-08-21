#pragma once
#include "book-search-engine.h"
#include "authenticator.h"

class AuthenticatedSearchEngine2 : public BookSearchEngine
{
    //ISearchEngine<E> *target;
    public:
    // AuthenticatedSearchEngine(ISearchEngine<E> *target)
    // {
    //     this->target=target;
    // }

    Result<Book> search(string query) override
    {
        if(!Authenticator::instance()->isAuthenticated())
        {
            Result<Book> result;
            result.error="Authentication failed";
            return result;
        }
        else
            return BookSearchEngine::search(query);
    }


};