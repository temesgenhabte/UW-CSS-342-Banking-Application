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
//
////
//// Created by Temesgen on 12/4/2019.
////
//
//#include "Bank.h"
//#include <iostream>
//#include <sstream>
//
//
//using namespace std;
//
//Bank::Bank(string fileName) {
//    this->fileName = fileName;
//}
//
//void Bank::readFile() {
//    ifstream inFile;
//    inFile.open(fileName); //.c_str() if you need it
//    string line;
//
//    if(inFile.is_open()) {
//
//        while (getline(inFile, line)) {
//            transactions.push(line);
//        }
//        inFile.close();
//    }else{
//        cout << "Unable to open file " << fileName << endl;
//        exit(1); //exits the code to avoid further crashes
//    }
//}
//
//void Bank::readQueue(){
//    string line;
//    char action;
//    int amount;
//    string accountFirstName;
//    string accountLastName;
//
//    while (!(transactions.empty())) {
//        istringstream readLine(transactions.front());
//        line = transactions.front();
//        transactions.pop();
//        action = line[0];
//
//        if (action == 'O') {
//            int accountId;
//            readLine >> accountLastName;
//            readLine >> accountFirstName;
//            readLine >> accountId;
//
//            Account *toAdd = new Account(accountFirstName, accountLastName, accountId);
//            accounts.Insert(toAdd); //insert into the tree
//        } else if (action == 'D') {
//            int accountId;
//            int fund;
//            readLine >> accountId;
//            fund = accountId % 10;
//            readLine >> amount;
//
//            Account *depositTo = nullptr;
//            if (accounts.Retrieve(accountId, depositTo)) {
//                depositTo->Deposit(amount, fund);
//            } else {
//                cout << "ERROR: Account " << accountId << " not found. Deposit refused." << endl;
//            }
//        } else if (action == 'W') {
//            int accountId;
//            int fund;
//            readLine >> accountId;
//            fund = accountId % 10;
//            readLine >> amount;
//
//            Account *withdrawFrom = nullptr;
//            if (accounts.Retrieve(accountId, withdrawFrom)) {
//                withdrawFrom->Withdraw(amount, fund);
//            } else {
//                cout << "ERROR: Account " << accountId << " not found. Withdrawal refused." << endl;
//            }
//        } else if (action == 'T') {
//            int accountId1;
//            int accountId2;
//            int fund1;
//            int fund2;
//            readLine >> accountId1;
//            fund1 = accountId1 % 10;
//            readLine >> amount;
//            readLine >> accountId2;
//            fund2 = accountId2 % 10;
//
//            Account *withdrawFrom = nullptr;
//            Account *depositTo = nullptr;
//            if (accounts.Retrieve(accountId1, withdrawFrom)) {
//                if (accounts.Retrieve(accountId2, depositTo)) {
//                    Transfer(amount, withdrawFrom, fund1, depositTo, fund2);
//                } else {
//                    cout << "ERROR: Account " << accountId2 << " not found. Transferal refused." << endl;
//                }
//            } else {
//                cout << "ERROR: Account " << accountId1 << " not found. Transferal refused." << endl;
//            }
//        } else if (action == 'H') {
//            cout << "DOING HISTORY STUFF" << endl;
//        }
//    }
//
//    cout << "DISPLAYING ALL OPEN ACCOUNTS IN TREE" << endl;
//    accounts.Display();
//}
//
//void Bank::openAccount(int accountId, string firstName, string lastName) {
//
//}
//
//void Bank::withdraw(int amount, Account *from) {
//
//}
//
//void Bank::deposit(int amount, Account *to) {
//
//}
//
///**
// * Transfer
// * This method transfers money from one fund
// * to another fund. This method fails if the
// * the fund "from" does not have enough money.
// * Returns false upon failure.
// * @param amount
// * @param from
// * @param to
// * @return
// */
//bool Bank::Transfer(int amount, Account *from, int fundFrom, Account *to, int fundTo) {
//    int amountWithdrawn = from->Withdraw(amount, fundFrom);
//    if(amountWithdrawn != -1){
//        to->Deposit(amountWithdrawn, fundTo);
//        return true;
//    }else{
//        return false;
//    }
//}
//
//void Bank::history(Account *view) {
//
//}
//
////for printing. finish the queue and then print everything in the tree. For "H" they provide the name so you can use that