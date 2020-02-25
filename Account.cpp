//
// Created by Temesgen on 12/4/2019.
//

#include "Account.h"
#include <vector>

using namespace std;

Account::Account(string lastName, string firstName, int accountNum){
    this->lastName = lastName;
    this->firstName = firstName;
    this->id = accountNum;
    funds[0].name = "Money Market";
    funds[1].name = "Prime Money Market";
    funds[2].name = "Long-Term Bond";
    funds[3].name = "Short-Term Bond";
    funds[4].name = "500 Index Fund";
    funds[5].name = "Capital Value Fund";
    funds[6].name = "Growth Equity Fund";
    funds[7].name = "Growth Index Fund";
    funds[8].name = "Value Fund";
    funds[9].name = "Value Stock Index";
}

Account::~Account(){
}

/**
 * Withdraw
 * This method withdraws a user specified amount from a
 * specific fund and then either returns the amount withdrawn
 * or a -1 indicating a failed attempt.
 * @param amount
 * @param from
 * @return
 */
int Account::Withdraw(int amount, int from) {
    if(from == 0 && funds[from].money < amount){ //check if other market fund
                                            //has sufficient money
        if(funds[1].money >= (amount - funds[from].money)){ //if so, pull from it
            funds[1].money -= (amount - funds[from].money); //update other fund
            funds[from].money = 0; //update original fund
            funds[from].fundHistory.push_back("W " + to_string(id)
                                  + to_string(from) + " " + to_string(amount));
            return amount;
        }else{
            cout << "ERROR: Not enough funds to withdraw " << amount << " from "
                << firstName << " " << lastName << " " << funds[from].name << endl;
            funds[from].fundHistory.push_back("W " + to_string(id)
                    + to_string(from) + " " + to_string(amount) + " (Failed)");
            return -1;
        }
    }else if(from == 1 && funds[from].money < amount){
        if(funds[0].money >= (amount - funds[from].money)){
            funds[0].money -= (amount - funds[from].money);
            funds[from].money = 0;
            funds[from].fundHistory.push_back("W " + to_string(id)
                                  + to_string(from) + " " + to_string(amount));
            return amount;
        }else{
            cout << "ERROR: Not enough funds to withdraw " << amount << " from "
                 << firstName << " " << lastName << " " << funds[from].name << endl;
            funds[from].fundHistory.push_back("W " + to_string(id)
                    + to_string(from) + " " + to_string(amount) + " (Failed)");
            return -1;
        }
    }else if(from == 2 && funds[from].money < amount){ //check if other market fund
        //has sufficient money
        if(funds[3].money >= (amount - funds[from].money)){ //if so, pull from it
            funds[3].money -= (amount - funds[from].money); //update other fund
            funds[from].money = 0; //update original fund
            funds[from].fundHistory.push_back("W " + to_string(id)
                                              + to_string(from) + " " + to_string(amount));
            return amount;
        }else{
            cout << "ERROR: Not enough funds to withdraw " << amount << " from "
                 << firstName << " " << lastName << " " << funds[from].name << endl;
            funds[from].fundHistory.push_back("W " + to_string(id)
                                              + to_string(from) + " " + to_string(amount) + " (Failed)");
            return -1;
        }
    }else if(from == 3 && funds[from].money < amount){
        if(funds[2].money >= (amount - funds[from].money)){
            funds[2].money -= (amount - funds[from].money);
            funds[from].money = 0;
            funds[from].fundHistory.push_back("W " + to_string(id)
                                              + to_string(from) + " " + to_string(amount));
            return amount;
        }else{
            cout << "ERROR: Not enough funds to withdraw " << amount << " from "
                 << firstName << " " << lastName << " " << funds[from].name << endl;
            funds[from].fundHistory.push_back("W " + to_string(id)
                                              + to_string(from) + " " + to_string(amount) + " (Failed)");
            return -1;
        }
    }else if(amount < 0) {
        cout << "ERROR: Cannot withdraw negative amount from "
             << firstName << " " << lastName << " " << funds[from].name << endl;
        funds[from].fundHistory.push_back("W " + to_string(id)
                                        + to_string(from) + " " + to_string(amount) + " (Failed)");
        return -1;
    }else if(from < 0 || from > 9) {
        cout << "ERROR: Cannot withdraw from fund that does not exist "
             << firstName << " " << lastName << " " << funds[from].name << endl;
        funds[from].fundHistory.push_back("W " + to_string(id)
                                          + to_string(from) + " " + to_string(amount) + " (Failed)");
        return -1;
    }else if(funds[from].money >= amount){
            funds[from].money -= amount;
            funds[from].fundHistory.push_back("W " + to_string(id)
            + to_string(from) + " " + to_string(amount));
            return amount;
    }else{
        cout << "ERROR: Not enough funds to withdraw " << amount << " from "
             << firstName << " " << lastName << " " << funds[from].name << endl;
        funds[from].fundHistory.push_back("W " + to_string(id)
                    + to_string(from) + " " + to_string(amount) + " (Failed)");
        return -1;
    }
}

/**
 * Deposit
 * This method deposit a specific amount from a
 * specific fund.
 * @param amount
 * @param from
 */
void Account::Deposit(int amount, int to) {
    if(amount >= 0) {
        funds[to].money += amount;
        funds[to].fundHistory.push_back("D " + to_string(id)
                      + to_string(to) + " " + to_string(amount));
    }else{
        cout << "ERROR: Cannot deposit negative amount " << " from "
             << firstName << " " << lastName << " " << funds[to].name << endl;
        funds[to].fundHistory.push_back("D " + to_string(id)
                                          + to_string(to) + " " + to_string(amount) + " (Failed)");
    }
}


/**
 * PrintHistory
 * This method will print the transaction
 * history of each fund.
 */
void Account::printHistory() {
    cout << "Transaction History for " << firstName << " " <<  lastName << " by fund." << endl;
    for(int i  = 0; i < 10; i++){
        cout << funds[i].name << ": " << "$" << to_string(funds[i].money) << endl;
        for(int j = 0; j < funds[i].fundHistory.size(); j++){
            cout << "  " <<  funds[i].fundHistory[j] << endl;
        }
    }
}

void Account::printFundHistory(int of){
    cout << "Transaction History for " << firstName << " " <<  lastName << " ";
    cout << funds[of].name << ": " << "$" << to_string(funds[of].money) << endl;
    for(int i = 0; i < funds[of].fundHistory.size(); i++){
        cout << funds[of].fundHistory[i] << endl;
    }
}

/** Operator Overload **/
ostream& operator<<(ostream &out, Account &account){
    cout << account.getFirstName() << " " << account.getLastName() <<
    " Account ID: " << account.getId() << endl;

    for(int i = 0; i < 10; i++){
        out << "    " << account.funds[i].name << ": " << "$" <<
        to_string(account.funds[i].money) << "\n";
    }
    out << "\n";
    return out;
}

/** GETTERS **/

int Account::getId(){
    return id;
}

string Account::getFirstName() {
    return firstName;
}

string Account::getLastName() {
    return lastName;
}

vector<string> Account::getHistory() {
    return history;
}