// ASSIGNMENT NO - 5
// NAME - YASH JITENDRA CHINCHOLE
// ROLL NO - SYCOA37

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    bool LeftThread, RightThread;
};

class TBT
{
private:
    Node *root;

public:
    TBT();
    void Insert(int);
    void InOrder();
};

TBT::TBT()
{
    root = new Node;
    root->right = root->left = root;
    root->LeftThread = true;
    root->data = INT_MAX;
}

void TBT::Insert(int key)
{
    Node *p = root;

    while (1)
    {
        if (p->data < key)
        {
            if (p->RightThread)
                break;
            p = p->right;
        }

        else if (p->data > key)
        {
            if (p->LeftThread)
                break;
            p = p->left;
        }

        else
            return;
    }

    Node *temp = new Node;
    temp->data = key;
    temp->RightThread = temp->LeftThread = true;

    if (p->data < key)
    {
        temp->right = p->right;
        temp->left = p;
        p->right = temp;
        p->RightThread = false;
    }

    else
    {
        temp->right = p;
        temp->left = p->left;
        p->left = temp;
        p->LeftThread = false;
    }
}

void TBT::InOrder()
{
    Node *temp = root, *p;
    for (;;)
    {
        p = temp;
        temp = temp->right;
        if (!p->RightThread)
        {
            while (!temp->LeftThread)
            {
                temp = temp->left;
            }
        }
        if (temp == root)
            break;
        cout << temp->data << " ";
    }
    cout << endl;
}

int main()
{
    TBT tbt;
    cout << "Threaded Binary Tree" << endl;
    tbt.Insert(20);
    tbt.Insert(10);
    tbt.Insert(30);
    tbt.Insert(5);
    tbt.Insert(16);
    tbt.Insert(14);
    tbt.Insert(17);
    tbt.Insert(13);
    tbt.InOrder();

    return 0;
}