//
// Created by Temesgen on 12/4/2019.
//

#include "Bank.h"
#include <iostream>
#include <sstream>


using namespace std;

Bank::Bank(string fileName) {
    this->fileName = fileName;
}

void Bank::readQueue() {
    ifstream inFile;
    inFile.open(fileName); //.c_str() if you need it
    string line;
    char action;
    int amount;
    string accountFirstName;
    string accountLastName;

    if(inFile.is_open()) {

        while (getline(inFile, line)) {
            transactions.push(line);
        }

        inFile.close();

        while (!(transactions.empty())) {
            istringstream readLine(transactions.front());
            line = transactions.front();
            transactions.pop();
            action = line[0];

            if (action == 'O') {
                int accountId;
                string garbage;
                readLine >> garbage;
                readLine >> accountLastName;
                readLine >> accountFirstName;
                readLine >> accountId;

                Account *toAdd = new Account(accountLastName, accountFirstName, accountId);
                if(!(accounts.Retrieve(accountId, toAdd))) {
                    accounts.Insert(toAdd);
                }else{
                    cout << "ERROR: Account " << accountId << " is already open. Transaction refused." << endl;
                }
            } else if (action == 'D') {
                int accountId;
                int fund;
                string garbage;
                readLine >> garbage;
                readLine >> accountId;
                fund = accountId % 10;
                accountId *= 0.1;
                readLine >> amount;

                Account *depositTo = nullptr;
                if (accounts.Retrieve(accountId, depositTo)) {
                    depositTo->Deposit(amount, fund);
                } else {
                    cout << "ERROR: Account " << accountId << " not found. Deposit refused." << endl;
                }
            } else if (action == 'W') {
                int accountId;
                int fund;
                string garbage;
                readLine >> garbage;
                readLine >> accountId;
                fund = accountId % 10;
                accountId *= 0.1;
                readLine >> amount;
                Account *withdrawFrom = nullptr;
                if (accounts.Retrieve(accountId, withdrawFrom)) {
                    withdrawFrom->Withdraw(amount, fund);
                } else {
                    cout << "ERROR: Account " << accountId << " not found. Withdrawal refused." << endl;
                }
            } else if (action == 'T') {
                int accountId1;
                int accountId2;
                int fund1;
                int fund2;
                string garbage;
                readLine >> garbage;
                readLine >> accountId1;
                fund1 = accountId1 % 10;
                accountId1 *= 0.1;
                readLine >> amount;
                readLine >> accountId2;
                fund2 = accountId2 % 10;
                accountId2 *= 0.1;

                Account *withdrawFrom = nullptr;
                Account *depositTo = nullptr;
                if (accounts.Retrieve(accountId1, withdrawFrom)) {
                    if (accounts.Retrieve(accountId2, depositTo)) {
                        Transfer(amount, withdrawFrom, fund1, depositTo, fund2);
                    } else {
                        cout << "ERROR: Account " << accountId2 << " not found. Transferal refused." << endl;
                    }
                } else {
                    cout << "ERROR: Account " << accountId1 << " not found. Transferal refused." << endl;
                }
            } else if (action == 'H') {
                int accountId;
                string numLength;
                int fund;
                string garbage;
                readLine >> garbage;
                readLine >> accountId;
                numLength = to_string(accountId);
                if(numLength.size() == 5){
                    fund = accountId %10;
                    accountId *= 0.1;
                    Account *historyOf = nullptr;
                    if (accounts.Retrieve(accountId, historyOf)) {
                        historyOf->printFundHistory(fund);
                    } else {
                        cout << "ERROR: Account " << accountId << " not found. View history refused." << endl;
                    }
                }else{
                    Account *historyOf = nullptr;
                    if (accounts.Retrieve(accountId, historyOf)) {
                        historyOf->printHistory();
                    } else {
                        cout << "ERROR: Account " << accountId << " not found. View history refused." << endl;
                    }
                }
            }
        }
        cout << "\n" << "Processing Done. Final Balances" << endl;
        accounts.Display();
    }
}

/**
 * Transfer
 * This method transfers money from one fund
 * to another fund. This method fails if the
 * the fund "from" does not have enough money.
 * Returns false upon failure.
 * @param amount
 * @param from
 * @param to
 * @return
 */
bool Bank::Transfer(int amount, Account *from, int fundFrom, Account *to, int fundTo) {
    int amountWithdrawn = from->Withdraw(amount, fundFrom);
    if(amountWithdrawn != -1){
        to->Deposit(amountWithdrawn, fundTo);
        return true;
    }else{
        return false;
    }
}

//for printing. finish the queue and then print everything in the tree. For "H" they provide the name so you can use that