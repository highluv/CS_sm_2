#include <iostream>
#include "tree.h"
#include "contact.h"  // чтобы использовать contacts[] массив

using namespace std;

//  TreeNode constructor 
TreeNode::TreeNode(int idx, int k)
    : contactIndex(idx), key(k), left(nullptr), right(nullptr) {}


//  BinaryTreeIndex constructor 
BinaryTreeIndex::BinaryTreeIndex() : root(nullptr) {}

TreeNode* BinaryTreeIndex::getRoot() {
    return root;
}


//  INSERT 
void BinaryTreeIndex::insert(int contactIndex, int key) {
    root = insertNode(root, contactIndex, key);
}

TreeNode* BinaryTreeIndex::insertNode(TreeNode* node, int contactIndex, int key) {
    if (node == nullptr) {
        return new TreeNode(contactIndex, key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, contactIndex, key);
    } else {
        node->right = insertNode(node->right, contactIndex, key);
    }

    return node;
}


//  PRINT ASC (in-order) 
void BinaryTreeIndex::printAscending() {
    printAscendingNode(root);
}

void BinaryTreeIndex::printAscendingNode(TreeNode* node) {
    if (node == nullptr) return;

    printAscendingNode(node->left);

    int i = node->contactIndex;
    if (!contacts[i].deleted) {
        cout << "ID: " << contacts[i].id
             << ", Name: " << contacts[i].name
             << ", Phone: " << contacts[i].phone << endl;
    }

    printAscendingNode(node->right);
}


//  PRINT DESC (reverse in-order) 
void BinaryTreeIndex::printDescending() {
    printDescendingNode(root);
}

void BinaryTreeIndex::printDescendingNode(TreeNode* node) {
    if (node == nullptr) return;

    printDescendingNode(node->right);

    int i = node->contactIndex;
    if (!contacts[i].deleted) {
        cout << "ID: " << contacts[i].id
             << ", Name: " << contacts[i].name
             << ", Phone: " << contacts[i].phone << endl;
    }

    printDescendingNode(node->left);
}


//  SEARCH (recursive) 
TreeNode* BinaryTreeIndex::searchRecursive(TreeNode* node, int key) {
    if (node == nullptr) return nullptr;

    if (key == node->key) return node;

    if (key < node->key)
        return searchRecursive(node->left, key);
    else
        return searchRecursive(node->right, key);
}


//  SEARCH (iterative) 
TreeNode* BinaryTreeIndex::searchIterative(int key) {
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (key == curr->key) return curr;

        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return nullptr;
}
