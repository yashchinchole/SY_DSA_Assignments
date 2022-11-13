// ASSIGNMENT NO - 1
// NAME - YASH JITENDRA CHINCHOLE
// ROLL NO - SYCOA37

#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

struct Employee
{
    int id, key;
    string name;
} Table[10];

class Hashtable
{
public:
    Hashtable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Table[i].id = -1;
            Table[i].key = -1;
            Table[i].name = "___";
        }
    }

    int Hash(int key)
    {
        return key % 10;
    }

    int Probing(struct Employee Table[], int id)
    {
        int i = 0, index = Hash(id);

        while (Table[(index + i) % SIZE].id != -1)
            i++;

        return (index + i) % SIZE;
    }

    void Insertion()
    {
        int i, emps;
        cout << "Enter Number of Employees" << endl;
        cin >> emps;

        for (i = 0; i < emps; i++)
        {
            int id, flag = 0;
            string name;

            cout << "Enter Employee Id " << endl;
            cin >> id;
            cout << "Enter Employee Name " << endl;
            cin >> name;

            int index = Hash(id);
            int c = index;

            if (Table[index].id != -1)
                index = Probing(Table, id);

            Table[index].id = id;
            Table[index].name = name;
            Table[index].key = c;
        }
    }

    void Deletion()
    {
        int x, i;
        cout << "Enter id to be deleted" << endl;
        cin >> x;

        for (i = 0; i < 10; i++)
        {
            if (x == Table[i].id)
            {
                Table[i].id = -1;
                Table[i].key = -1;
                Table[i].name = "___";
            }
        }
    }

    void Searching()
    {
        int iKey, i;
        cout << "Enter the id to be searched " << endl;
        cin >> iKey;

        for (i = 0; i < 10; i++)
        {
            if (iKey == Table[i].id)
            {
                cout << "Employee Name : " << Table[i].name << endl;
                cout << "Employee found at index " << i << endl;
            }
        }
    }

    void Display()
    {
        cout << "\n\tIndex \t\tId \t\tName " << endl;

        int i;
        for (i = 0; i < 10; i++)
            cout << "\n\t" << i << "\t\t" << Table[i].id << "\t\t" << Table[i].name << endl;
    }
};

int main()
{
    int ch, end;
    Hashtable emp;

    do
    {
        cout << endl;
        cout << "1. Insert Data" << endl;
        cout << "2. Delete Data" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. View Table" << endl;

        cin >> ch;
        switch (ch)
        {
        case 1:
            emp.Insertion();
            break;

        case 2:
            emp.Deletion();
            break;

        case 3:
            emp.Searching();
            break;

        case 4:
            emp.Display();
            break;

        default:
            cout << "Invalid Input" << endl;
        }

        cout << "Do you want to continue?? (0 = No, 1 = Yes )" << endl;
        cin >> end;
    } while (end == 1);

    return 0;
}