#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Stack
{
private:
    Node *top = NULL;

public:
    void Push(int);
    int Pop();
    void Peek(int);
    void Display();
};

void Stack::Push(int data)
{
    Node *temp = new Node;

    if (!temp)
        cout << "Stack Overflow" << endl;

    else
    {
        temp->data = data;
        temp->next = top;
        top = temp;
    }
}

int Stack::Pop()
{
    int x = -1;

    if (!top)
        cout << "Stack Underflow" << endl;

    else
    {
        Node *temp = top;
        top = top->next;
        x = temp->data;
        delete temp;
    }

    return x;
}

void Stack ::Peek(int p)
{
    Node *temp = top;

    for (int i = 0; i < p - 1 && temp != NULL; i++)
        temp = temp->next;

    if (!temp)
        cout << "Incorrect Position" << endl;

    else
        cout << p << " Position Element : " << temp->data << endl;
}

void Stack::Display()
{
    Node *temp = top;

    if (!top)
        cout << "Stack is Empty" << endl;

    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Peek(2);
    s.Display();
    s.Pop();
    s.Display();

    return 0;
}