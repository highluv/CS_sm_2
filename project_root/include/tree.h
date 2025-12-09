#ifndef TREE_H
#define TREE_H

#include "contact.h"  

// Узел бинарного дерева
struct TreeNode {
    int contactIndex;   // индекс контакта в массиве contacts[]
    int key;            // ключ сортировки — ID контакта
    TreeNode* left;
    TreeNode* right;

    TreeNode(int idx, int k);
};

// Бинарное дерево для индексации по ID
class BinaryTreeIndex {
private:
    TreeNode* root;

    // внутренние рекурсивные функции
    TreeNode* insertNode(TreeNode* node, int contactIndex, int key);
    void printAscendingNode(TreeNode* node);
    void printDescendingNode(TreeNode* node);

public:
    BinaryTreeIndex();
    void insert(int contactIndex, int key);
    void printAscending();
    void printDescending();

    TreeNode* searchRecursive(TreeNode* node, int key);
    TreeNode* searchIterative(int key);

    TreeNode* getRoot(); // для рекурсивного поиска
};

#endif
