//
// Created by Temesgen on 12/4/2019.
//

#include "BSTree.h"

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    Empty();
}

/**
 * Insert
 * This method inserts an Account in the correct position.
 * It uses a helper method to recursively find the correct
 * position to add.
 * @param toAdd
 * @return
 */
bool BSTree::Insert(Account *toAdd) {
    Node* cur = root;
    if(cur == nullptr){
        Node* newNode = new Node();
        newNode->pAcct = toAdd;
        newNode->left = nullptr;
        newNode->right = nullptr;
        root = newNode;
        return true;
    }else{
        Insert(toAdd, root);
    }

    return true;
}

BSTree::Node* BSTree::Insert(Account *toAdd, Node* curRoot) {
    if (curRoot == nullptr) {
        Node* newNode = new Node;
        newNode->pAcct = toAdd;
        newNode->left = nullptr;
        newNode->right = nullptr;
        curRoot = newNode;
        return newNode;
    }else{
        if(curRoot->pAcct->getId() == toAdd->getId()){
            return nullptr;
        }else if (toAdd->getId() < curRoot->pAcct->getId()) {
            curRoot->left = Insert(toAdd, curRoot->left);
        }else{
            curRoot->right = Insert(toAdd, curRoot->right);
        }
    }
    return curRoot;
}

bool BSTree::Retrieve(const int & accountId, Account *& toFind) const {
    return Retrieve(accountId, toFind, root);
}

bool BSTree::Retrieve(const int& accountId, Account*& toFind, Node* curRoot) const{
    if(curRoot == nullptr){
        return false;
    }else{
        if(curRoot->pAcct->getId() == accountId){
            toFind = curRoot->pAcct;
            return true;
        }else if(accountId < curRoot->pAcct->getId()){
            return Retrieve(accountId, toFind, curRoot->left);
        }else{
            return Retrieve(accountId, toFind, curRoot->right);
        }
    }
}

void BSTree::Display() const {
    Display(root);
}

void BSTree::Display(Node* curRoot) const{
    if(curRoot != nullptr){
        Display(curRoot->left);
        cout << *(curRoot->pAcct) << endl;
        Display(curRoot->right);
    }
}

void BSTree::Empty() {
    Empty(root);
}

void BSTree::Empty(Node* curRoot){
    if(curRoot != nullptr){
        Empty(curRoot->left);
        Empty(curRoot->right);
        delete curRoot->pAcct;
        delete curRoot;
    }
}

bool BSTree::isEmpty() const {
    return (root == nullptr);
}


