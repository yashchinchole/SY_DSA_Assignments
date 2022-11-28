// ASSIGNMENT NO - 4 PART - 2
// NAME - YASH JITENDRA CHINCHOLE
// ROLL NO - SYCOA37

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *front = NULL, *rear = NULL;

class Queue
{
public:
    void enQueue();
    void deQueue();
    void Display();
    void Peek();
};

void Queue::enQueue()
{
    int num;
    cout << "Enter Number" << endl;
    cin >> num;

    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = NULL;

    if (rear != NULL)
    {
        rear->next = newnode;
        rear = newnode;
    }

    else
        front = rear = newnode;
}

void Queue::deQueue()
{
    if (front != NULL)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    else
        cout << "Queue is empty!\n";
}

void Queue::Peek()
{
    if (front != NULL)
        cout << "\nFront element is: " << front->data << "\n";

    else
        cout << "Queue is empty!\n";
}

void Queue::Display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Queue q;

    while (1)
    {
        int cho;
        cout << "Enter Choice" << endl;
        cout << "1 - EnQueue  |  2 - DeQueue  |  3 - Peek  |  4 - Display  |  5 - Exit\n";
        cin >> cho;

        switch (cho)
        {
        case 1:
            q.enQueue();
            break;
        case 2:
            q.deQueue();
            q.Display();
            break;
        case 3:
            q.Peek();
            break;
        case 4:
            q.Display();
            break;
        case 5:
            exit(0);
        }
    }

    return 0;
}