#include "binaryTree.h"



//Node* treeFind(Node* root, int key){
//    while (root){
//        if (root->key > key){
//            root = root->left;
//        }
//        else if (root->key < key){
//            root = root->right;
//        }
//        else return root;
//    }
//    return nullptr;
//}

Node* treeAdd(Node* root, int key){
    Node* bufRoot = root;
    if (!root){
        root = new Node ();
        root->key = key;
        root->number = 1;
        return root;
    }
    Node* par = nullptr;
    while (root){
        if (root->key > key){
            par = root;
            root = root->left;
        }
        else if (root->key < key){
            par = root;
            root = root->right;
        }
        else {
            (root->number)++;
            return bufRoot;
        }
    }
    if (key > par->key){
        par->right = new Node ();
        par->right->key = key;
        par->right->number = 1;
        return bufRoot;
    }
    else {
        par->left = new Node ();
        par->left->key = key;
        par->left->number = 1;
        return bufRoot;
    }
}

unsigned int maxOfThreeNum(unsigned int a, unsigned int b, unsigned int c){
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    return c;
}


unsigned int treeGetMaxNumber(Node* root){
    if (!root) return 0;
    unsigned int left = treeGetMaxNumber(root->left);
    unsigned int right = treeGetMaxNumber(root->right);
    return maxOfThreeNum(left, right, root->number);
}


void treeFree(Node* root){
    if (!root) return;
    treeFree(root->left);
    treeFree(root->right);
    delete root;
}


