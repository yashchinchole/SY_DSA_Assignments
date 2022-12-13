#include <iostream>
#include <iomanip>
using namespace std;

void MergeSort(int A[], int low, int high);
void Merge(int A[], int mid, int low, int high);

int main()
{
    int i, n, count = 0, arr[100];
    cout << "Enter Number of Employees : ";
    cin >> n;
    cout << "\nEnter Salary of " << n << " employees" << endl;

    for (i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nArray Before Sorting" << endl;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    MergeSort(arr, 0, n - 1);

    cout << "\n\nArray After Sorting" << endl;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nTop 5 Performers" << endl;
    for (i = n - 1; i >= 0; i--)
    {
        if (count == 5)
            break;

        cout << arr[i] << " ";
        count++;
    }

    return 0;
}

void MergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, mid, low, high);
    }
}

void Merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }

        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++)
        A[i] = B[i];
}