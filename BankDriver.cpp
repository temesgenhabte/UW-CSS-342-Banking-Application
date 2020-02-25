//
// Created by Temesgen on 12/6/2019.
//

#include <iostream>
#include "Bank.h"

using namespace std;

int main(int argc, char *argv[]){
    Bank *bank = new Bank(argv[1]);
    bank->readQueue();
}
