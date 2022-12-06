// In one-way threaded binary trees, a thread will appear either in the right or left link field of a node. If it appears in the right link field of a node then it will point to the next node that will appear on performing in order traversal. Such trees are called Right threaded binary trees. If thread appears in the left field of a node then it will point to the nodes inorder predecessor. Such trees are called Left threaded binary trees. Left threaded binary trees are used less often as they don't yield the last advantages of right threaded binary trees. In one-way threaded binary trees, the right link field of last node and left link field of first node contains a NULL. In order to distinguish threads from normal links they are represented by dotted lines.

// https://www.javatpoint.com/threaded-binary-tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    bool rightThread;
};

Node *Newnode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *leftMost(struct Node *n)
{
    if (n == NULL)
        return NULL;

    while (n->left != NULL)
        n = n->left;

    return n;
}

void inOrder(struct Node *root)
{
    struct Node *cur = leftMost(root);
    while (cur != NULL)
    {
        cout << cur->data;

        if (cur->rightThread)
            cur = cur->right;
        // else
            // cur = leftmost(cur->right);
    }
}

void Inorder(struct Node *node)
{
    if (node == NULL)
        return;

    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}

void Preorder(struct Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct Node *node)
{
    if (node == NULL)
        return;

    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << " ";
}

int main()
{
    struct Node *root = Newnode(1);
    root->left = Newnode(2);
    root->right = Newnode(3);
    root->left->left = Newnode(4);
    root->left->right = Newnode(5);

    cout << "Inorder : ";
    Inorder(root);
    cout << "\nPreorder : ";
    Preorder(root);
    cout << "\nPostorder : ";
    Postorder(root);

    return 0;
}