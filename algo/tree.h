
#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
struct Node
{
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int info) : data(info) {}
};
///////////////////////////////////////////////////////////////////////////////
class Tree
{
public:

    struct Node * root = nullptr;
    void InOrderTraverstal(Node *tree);
    void PostOrderTraversal(Node *tree);
    void PreOrderTraversal(Node *tree);
    void InorderTraversalNR(Node *tree);  // No recusion function
    void PostorderTraversalNR(Node *tree);
    void PreorderTraversalNR(Node *tree);
    int GetHeight(Node *tree);
    void LevelOrderTraversal(Node *tree, std::vector<int> &nodeList);
    void PrintBoundaryNodes(Node *tree);
    void ZigZagTraversal(Node *root, std::vector<int> &nodeList);
    bool HasPathSum(Node *root, int &sum);
    void PrintRightView(Node *root);
    void rightView(struct Node *root);
    // Height of Tree function
    // diameter of a binary tree
    // number of nodes in longest path
};
