#include <iostream>
#include <string>
using namespace std;

class BankAccount{

public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;   
    virtual double getBalance() const = 0;
    virtual ~BankAccount() = default;

    virtual void transfer(BankAccount& to, double amount) =0;

};

class LoanAccount : public BankAccount {
private:
    double balance;
    int accountNumber;
    
    public:
    void deposit(double amount) { balance-=amount;}

};

int main(){
    LoanAccount account ;
    account->deposit(1000);
    account->withdraw(200);
    cout << "Balance: " << account->getBalance() << endl;
}