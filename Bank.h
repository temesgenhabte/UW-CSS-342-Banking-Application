//
// Created by Temesgen on 12/4/2019.
//

#ifndef HW6_BANKING_BANK_H
#define HW6_BANKING_BANK_H

#include <iostream>
#include <queue>
#include <fstream>
#include "BSTree.h"
#include "Account.h"

using namespace std;

class Bank {
private:
    BSTree accounts;
    queue<string> transactions;
    string fileName;

public:
    Bank(string fileName);
    ~Bank();
    void readFile();
    void readQueue();
    void openAccount(int accountId, string firstName, string lastName);
    void withdraw(int amount, Account *from);
    void deposit(int amount, Account *to);
    bool Transfer(int amount, Account *from, int fundFrom, Account *to, int fundTo);
    void history(Account *view);
    void printOpenAccounts();
};


#endif //HW6_BANKING_BANK_H
