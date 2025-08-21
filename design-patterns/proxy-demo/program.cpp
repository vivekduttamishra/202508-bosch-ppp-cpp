#include <iostream>
#include <string>
#include <string.h>
#include "book-search-engine.h"
#include "cached-search.h"
#include "authenticator.h"
#include "inheritance-proxy.h"
using namespace std;

void ShowBooks(vector<Book *> &books, string label)
{
    cout << label << endl;

    for (auto book : books)
    {
        cout << book->title << "\t" << book->author << "\t" << book->price << endl;
    }

    cout << "--------------------------------" << endl
         << endl;
}

bool confirm(string message)
{
    string confirm;
    cout<<message;
    std::getline(cin, confirm);
    return confirm=="y";
}

ISearchEngine<Book> * buildEngine()
{
    ISearchEngine<Book> *engine= new BookSearchEngine;

    if(confirm("Need caching?"))
        engine= new CachedSearchEngine<Book>(engine);

    if(confirm("Need Authentication?"))
    {
        engine=new AuthenticatedSearchEngine<Book>(engine);
    }

    return engine;


}

void testSearch(ISearchEngine<Book> * engine)
{
    string queries[]={"Vivek","Dinkar","Archer","Vivek","Archer"};

    for(auto query : queries)
    {
        cout<<"querying for "<<query<<endl;
        auto result=engine->search(query);
        if(!result.error.empty()){
            cout<<"ERROR:"<<result.error<<endl;
        }
        else
        {
            ShowBooks(result.values, string("Query:")+query);
        }
    }
}

int main()
{
    auto books = BookManager::instance()->getBooks();
   // ShowBooks(books, "Original List");

    char q[100];
    string query;

    //auto engine = new BookSearchEngine();
    string username;
    string password;
    cout<<"user?";
    std::getline(std::cin, username);
    if (!username.empty())
    {
        cout<<"pasword?";
        string password;
        std::getline(std::cin, password);
        Authenticator::instance()->authenticate(username, password);
    }
    //ISearchEngine<Book> * engine = buildEngine();
    
    ISearchEngine<Book> * engine = new AuthenticatedSearchEngine2;

    testSearch(engine);

   
}