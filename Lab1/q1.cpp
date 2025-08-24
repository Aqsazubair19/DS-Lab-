#include<iostream>
using namespace std;

class BankAccount{
    public:
    float balance;

    
    BankAccount(){
        balance = 0.0;
    }

    BankAccount(float balance): balance(balance){}

    void print(){
        cout<<balance<<endl;
    }

    void withdraw(float amount){
        balance -=amount;
    }
};
    

int main(){
    BankAccount account1;
    cout<<"balance of account 1:";
    account1.print();

    cout<<endl;
    BankAccount account2(1000);
    cout<<"balance of account 2:";
    account2.print();
    
    BankAccount account3(account2);
    account3.withdraw(200);
    cout<<"balance of account 3: ";
    account3.print();

    cout<<endl;

     cout<<"balance of account 2:";
     account2.print();
    
}
