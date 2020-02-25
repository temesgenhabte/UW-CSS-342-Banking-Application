//
// Created by Temesgen Habte
// The Account class defines the methods that the user can perform between multiple
// Accounts and between funds within an account.
//

#ifndef HW6_BANKING_ACCOUNT_H
#define HW6_BANKING_ACCOUNT_H

#include <iostream>
#include <vector>

using namespace std;

class Account {
private:
    int id;
    string firstName;
    string lastName;
    vector<string> history;

    struct Fund{
        string name;
        int money = 0;
        vector<string> fundHistory;
    };

    Fund funds[10];

public:
    Account(string lastName, string firstName, int accountNum); //constructor used when O is read
    ~Account();
    int Withdraw(int amount, int from);
    void Deposit(int amount, int to);
    bool Transfer(int amount, int from, int to);
    void printHistory();
    void printFundHistory(int of);

    int getId();
    string getFirstName();
    string getLastName();
    vector<string> getHistory();
    friend ostream& operator<<(ostream& out, Account &account);

//    bool openAccount();
};


#endif //HW6_BANKING_ACCOUNT_H
