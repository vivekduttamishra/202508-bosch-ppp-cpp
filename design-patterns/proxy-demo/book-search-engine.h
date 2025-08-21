#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "search-engine.h"

using namespace std;


struct Book
{
    string title;
    string author;
    int price;
};

class BookManager
{
    vector<Book*> books;
   
    BookManager()
    {
        books.push_back(new Book{"The Accursed God", "Vivek Dutta Mishra", 299});
        books.push_back(new Book{"Rashmirathi", "Ramdhari Singh Dinkar", 99});
        books.push_back(new Book{"Manas", "Vivek Dutta Mishra", 199});
        books.push_back(new Book{"Kurukshetra", "Ramdhari Singh Dinkar", 109});
        books.push_back(new Book{"Brethren", "John Grisham", 399});
    }


 public:
    vector<Book*> getBooks(){return books;}

    static BookManager* instance()
    {
        static BookManager * instance=new BookManager();
        return instance;
    }
};


class BookSearchEngine:public ISearchEngine<Book>
{
    
    public:
    Result<Book> search(string query)
    {
        Result<Book> result;
        
        for(auto book : BookManager::instance()->getBooks() )
        {
            if(book->author.find(query) != string::npos)
                result.values.push_back(book);
        }

        if(result.values.size() == 0)
            result.error="No books found";

        return result;
    }
};