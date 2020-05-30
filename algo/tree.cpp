
#include "stdafx.h"
#include "tree.h"

///////////////////////////////////////////////////////////////////////////////
void Tree::InOrderTraverstal(Node * tree)
{
    // This is DFS algorithm, where first Left, Root, Right

    if (tree == nullptr)
        return;

    InOrderTraverstal(tree->left);
    std::cout << tree->data << std::endl;
    InOrderTraverstal(tree->right);
    
}
///////////////////////////////////////////////////////////////////////////////
void Tree::PostOrderTraversal(Node *tree)
{
    // Left, Right, Root
    if (tree == nullptr)
        return;
    PostOrderTraversal(tree->left);
    PostOrderTraversal(tree->right);
    std::cout << tree->data << std::endl;
}
///////////////////////////////////////////////////////////////////////////////
void Tree::PreOrderTraversal(Node *tree)
{
    // Root, Left, Right
    if (tree == nullptr)
        return;

    std::cout << tree->data << std::endl;
    PreOrderTraversal(tree->left);
    PreOrderTraversal(tree->right);
}
///////////////////////////////////////////////////////////////////////////////
void Tree::InorderTraversalNR(Node *tree)
{
    if (tree == nullptr)
        return;

    // Left, Root and Right
    std::stack<Node *> stk;
    Node *current = tree;

    //current 
    while (current != NULL || !stk.empty())
    {
        while (current != NULL)
        {
            stk.push(current);
            current = current->left;
        }

        // Now current must be NULL as we have reached end of left node
        // pop from the stack
        current = stk.top();
        stk.pop();
        std::cout << current->data << std::endl;

        current = current->right;
    }
}
//////
// Root Left Right
///////////////////////////////////////////////////////////////////////////////
void Tree::PreorderTraversalNR(Node *tree)
{
    if (tree == nullptr)
        return;

    Node *temp = tree;
    std::stack<Node *> stk;
    stk.push(tree);

    while (!stk.empty())
    {
        temp = stk.top();
        stk.pop();
        std::cout << temp->data << std::endl;
        if (temp->right) stk.push(temp->right);
        if (temp->left) stk.push(temp->left);
    }
}
///////////////////////////////////////////////////////////////////////////////
void Tree::PostorderTraversalNR(Node *tree)
{
    // To be done
}
///////////////////////////////////////////////////////////////////////////////
int Tree::GetHeight(Node *tree)
{
    if (tree == nullptr)
        return 0;

    int left = GetHeight(tree->left);
    int right = GetHeight(tree->right);
    return max(left, right) + 1;
}
///////////////////////////////////////////////////////////////////////////////
void Tree::LevelOrderTraversal(Node *root, std::vector<int> &nodeList)
{
    if (root == NULL)
        return;

    std::queue<Node *> queue;
    queue.push(root);

    int depth = 0;
    while (!queue.empty())
    {
        ++depth;
        auto level = queue.size();

        while (level != 0)
        {
            Node * tmp = queue.front();

            std::cout << tmp->data << std::endl;
            queue.pop();
            nodeList.push_back(tmp->data);

            --level;
            if (tmp->left != NULL)
                queue.push(tmp->left);

            if (tmp->right != NULL)
                queue.push(tmp->right);
        }
    }

    std::cout << "Depth of tree " << depth << std::endl;
}
//////////////////////////////////////////////////////////////////////////////
void PrintBoundaryLeft(Node *root)
{
    if (root == NULL)
        return;


    // There can be four condition.
    // 1 Only left node
    // Only right node
    // Both left and right node
    // No nodes (don't handle)

    if (root->left)
    {
        std::cout << root->data << std::endl;
        PrintBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        std::cout << root->data << std::endl;
        PrintBoundaryLeft(root->right);
    }

}

//////////////////////////////////////////////////////////////////////////////
void PrintBoundaryRight(Node *root)
{
    if (root == NULL)
        return;


    // There can be four condition.
    // 1 Only right node
    // Only left node
    // Both left and right node
    // No nodes (don't handle)

    if (root->right)
    {
        std::cout << root->data << std::endl;
        PrintBoundaryRight(root->right);
    }
    else if (root->left)
    {
        std::cout << root->data << std::endl;
        PrintBoundaryRight(root->left);
    }

}

//////////////////////////////////////////////////////////////////////////////
void PrintLeaf(Node *root)
{
    if (root == NULL)
        return;

    PrintLeaf(root->left);

    // No child nodes
    if (root->left == NULL && root->right == NULL)
        std::cout << root->data << std::endl;
 //   else
//    {
        PrintLeaf(root->right);
//    }

}

///////////////////////////////////////////////////////////////////////////////
void Tree::PrintBoundaryNodes(Node *root)
{
    if (root == NULL)
        return;
    // First print the root itself
    std::cout << root->data << std::endl;
    PrintBoundaryLeft(root->left);
    PrintLeaf(root->left);
    PrintLeaf(root->right);
    PrintBoundaryRight(root->right);

}
///////////////////////////////////////////////////////////////////////////////
void Tree::ZigZagTraversal(Node *root, std::vector<int> &nodeList)
{
    if (root == NULL)
        return;

    std::queue<Node *> que;
    que.push(root);
    int level = 0;
    while (!que.empty())
    {
        ++level;
        auto size = que.size();

        std::stack<Node *> Stk;
        while (size > 0)
        {
            --size;
            Node *tmp = que.front();
            que.pop();

            if (level % 2 == 0)
            {
                Stk.push(tmp);
            }
            else
                std::cout << tmp->data << std::endl;

            if (tmp->left != NULL)
                que.push(tmp->left);

            if (tmp->right != NULL)
                que.push(tmp->right);
        }
        // Print the even stack:
        while (!Stk.empty())
        {
            std::cout << Stk.top()->data << std::endl;
            Stk.pop();
        }
    }
}
///////////////////////////////////////////////////////////////////////////////
bool Tree::HasPathSum(Node *root, int &sum)
{
    if (root == NULL)
        return false;

    bool hasPath = false;

    sum = sum - root->data;

    if (sum == 0 && root->left == NULL && root->right == NULL)
        return true;

    if (root->left != NULL)
        hasPath |= HasPathSum(root->left, sum);

    if (root->right != NULL)
        hasPath |= HasPathSum(root->right, sum);

    return hasPath;
}
///////////////////////////////////////////////////////////////////////////////
void Tree::PrintRightView(Node *root)
{
    if (root == NULL)
        return;

// Try using level order traversal technique.
}

// write algortihm for
// 1 pre order traversal
// 2 post order traversal
// 3 In order traversal
// Morris algorithm
// what is segment tree
// 

// Link list
// Reverse a link list

