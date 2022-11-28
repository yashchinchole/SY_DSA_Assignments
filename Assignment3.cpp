// ASSIGNMENT NO - 3
// NAME - YASH JITENDRA CHINCHOLE
// ROLL NO - SYCOA37

#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    char ch;
    Stack *next;
};

int Precd(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void push(Stack **head, char c)
{
    Stack *temp = new Stack;
    temp->next = *head;
    temp->ch = c;
    *head = temp;
}

char pop(Stack **head)
{
    char popped = (*head)->ch;
    Stack *temp = *head;
    *head = (*head)->next;
    free(temp);

    return popped;
}

char top(Stack **head)
{
    char topch = (*head)->ch;
    return topch;
}

bool isEmpty(Stack **head)
{
    if (*head == NULL)
        return true;
    else
        return false;
}

void Display(Stack **head)
{
    Stack *temp = *head;
    cout << "After Conversion from Infix to Postfix" << endl;
    while (temp->next != NULL)
    {
        cout << temp->ch;
        temp = temp->next;
    }
}

void Infix_2_Postfix(Stack **head, string s)
{
    string res;
    char c;
    for (int i = 0; i < s.length(); i++)
    {
        c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            res += c;

        else if (c == '(')
            push(head, '(');

        else if (c == ')')
        {
            while (top(head) != '(')
            {
                res += top(head);
                pop(head);
            }
            pop(head);
        }

        else
        {
            while (Precd(s[i]) <= Precd(top(head)))
            {
                res = res + top(head);
                pop(head);
            }
            push(head, c);
        }
    }

    while (!isEmpty(head))
    {
        res = res + top(head);
        pop(head);
    }
    cout << res << endl;
}

int main()
{
    string exp;
    cout << "Enter Expression" << endl;
    cin >> exp;

    Stack *head = NULL;
    push(&head, ' ');
    Display(&head);
    Infix_2_Postfix(&head, exp);

    return 0;
}