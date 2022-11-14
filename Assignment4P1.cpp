// ASSIGNMENT NO - 4 PART - 1
// NAME - YASH JITENDRA CHINCHOLE
// ROLL NO - SYCOA37

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *top = NULL;

class Stack
{
public:
    void Push();
    void Pop();
    void Peek();
    void Display();
};

void Stack::Push()
{
    int num;
    cout << "Enter Number to Push" << endl;
    cin >> num;

    Node *newnode = new Node;
    if (!newnode)
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    newnode->data = num;
    newnode->next = top;
    top = newnode;
}

void Stack::Pop()
{
    if (top)
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    else
        cout << "Stack Underflow" << endl;
}

void Stack::Peek()
{
    if (top)
        cout << "\nTop Element : " << top->data << endl;

    else
        cout << "Stack is empty" << endl;
}

void Stack::Display()
{
    Node *temp = top;
    cout << "Elements in Stack" << endl;

    if (top)
    {
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }

    else
        cout << "Stack is empty" << endl;
}

int main()
{
    Stack s;

    while (1)
    {
        int cho;
        cout << "Enter Choice" << endl;
        cout << "1 - Push  |  2 - Pop  |  3 - Peek  |  4 - Display  |  5 - Exit\n";
        cin >> cho;

        switch (cho)
        {
        case 1:
            s.Push();
            break;
        case 2:
            s.Pop();
            s.Display();
            break;
        case 3:
            s.Peek();
            break;
        case 4:
            s.Display();
            break;
        case 5:
            exit(0);
        }
    }

    return 0;
}