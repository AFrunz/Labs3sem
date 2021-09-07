#ifndef CPP_BINARYTREE_H
#define CPP_BINARYTREE_H

struct Node {
    int key;
    unsigned int number;
    Node* left;
    Node* right;
};

Node* treeFind(Node* root, int key);

Node * treeAdd(Node* root, int key);

void treeFree(Node* root);

unsigned int treeGetMaxNumber(Node* root);

#endif //CPP_BINARYTREE_H
