//
// Created by Temesgen on 12/4/2019.
//

#ifndef HW6_BANKING_BSTREE_H
#define HW6_BANKING_BSTREE_H

#include "Account.h"


class BSTree {
public:
    BSTree();
    ~BSTree();
    bool Insert(Account *);
// retrieve object, first parameter is the ID of the account
// second parameter holds pointer to found object, NULL if not found
    bool Retrieve(const int &, Account * &) const;
// displays the contents of a tree to cout
    void Display() const;
    void Empty();
    bool isEmpty() const;
private:
    struct Node
    {
        Account *pAcct;
        Node *right;
        Node *left;
    };
    Node *root;

    Node* Insert(Account* toAdd, Node* curRoot);
    bool Retrieve(const int& accountId, Account*& toFind, Node* curRoot) const;
    void Display(Node* curRoot) const;
    void Empty(Node* curRoot);
};


#endif //HW6_BANKING_BSTREE_H
