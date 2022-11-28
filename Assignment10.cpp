// ASSIGNMENT NO - 10
// NAME - YASH JITENDRA CHINCHOLE
// ROLL NO - SYCOA37

#include <bits/stdc++.h>
using namespace std;

class DLL
{
public:
    int data;
    DLL *next;
    DLL *prev;
};

void addAtFirst(DLL **head, int data)
{
    DLL *newNode = new DLL();
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

void addLast(DLL **head, int data)
{
    DLL *newNode = new DLL();
    newNode->data = data;

    DLL *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    newNode->prev = temp;
    temp->next = newNode;
    newNode->next = NULL;
}

void printList(DLL **head)
{
    DLL *temp = *head;
    cout << "\nDoubly linked list is : " << endl;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
}

void insertAfter(DLL **head, int prev_data, int data)
{
    DLL *newNode = new DLL();
    newNode->data = data;

    DLL *temp = *head;
    while (temp->data != prev_data)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtStart(DLL **head)
{
    DLL *temp = *head;
    *head = (*head)->next;
    ((*head)->next)->prev = NULL;
    free(temp);
}

void deleteAtEnd(DLL **head)
{
    DLL *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    (temp->prev)->next = NULL;
    free(temp);
}

void deleteAtPosition(DLL **head, int data)
{
    DLL *temp = *head;
    while (temp->data != data)
        temp = temp->next;

    if (temp->next != NULL)
        (temp->next)->prev = temp->prev;

    if (temp->prev != NULL)
        (temp->prev)->next = temp->next;
}

void searchElement(DLL **head, int data)
{
    DLL *temp = *head;
    int count = 1;

    while (temp->data != data && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp->data == data)
        cout << "\nElement is present at index " << count;
    else
        cout << "\nElement is not present ";
}

int main()
{
    DLL *head = NULL;
    int ch;
    int n, m;

    do
    {
        cout << "\n1.Enter data at first position ";
        cout << "\n2.Enter data at last position ";
        cout << "\n3.Enter data at a particular position ";
        cout << "\n4.Delete data at first position ";
        cout << "\n5.Delete data at last position ";
        cout << "\n6.Search data";
        cout << "\n7.Display";
        cout << "\n8.Exit";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter data : ";
            cin >> n;
            addAtFirst(&head, n);
            break;
        case 2:
            cout << "\nEnter data : ";
            cin >> n;
            addLast(&head, n);
            break;
        case 3:
            cout << "\nEnter previous data element : ";
            cin >> m;
            cout << "\nEnter data : ";
            cin >> n;

            insertAfter(&head, m, n);
            break;
        case 4:
            deleteAtStart(&head);
            break;
        case 5:
            deleteAtEnd(&head);
            break;
        case 6:
            cout << "\nEnter data to search : ";
            cin >> n;
            searchElement(&head, n);
        case 7:
            printList(&head);
            break;
        default:
            break;
        }
    } while (ch);

    return 0;
}