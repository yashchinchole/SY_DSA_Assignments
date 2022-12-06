// ASSIGNMENT NO - 11
// NAME - YASH JITENDRA CHINCHOLE
// ROLL NO - SYCOA37

#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *left, *right;

public:
    Node();
    Node(int);
    Node *Insert(Node *, int);
    Node *Search(Node *, int);
    Node *Delete(Node *, int);
    void Inorder(Node *);
};

Node::Node()
    : data(0), left(NULL), right(NULL)
{
}

Node ::Node(int value)
{
    data = value;
    left = right = NULL;
}

Node *Node ::Insert(Node *root, int value)
{
    if (!root)
        return new Node(value);

    if (value < root->data)
        root->left = Insert(root->left, value);

    else if (value > root->data)
        root->right = Insert(root->right, value);

    return root;
}

void Node::Inorder(Node *root)
{
    if (!root)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main()
{
    Node bst;
    Node *root = NULL;
    root = bst.Insert(root, 5);
    bst.Insert(root, 3);
    bst.Insert(root, 1);
    bst.Insert(root, 2);
    bst.Insert(root, 4);

    bst.Inorder(root);

    return 0;
}