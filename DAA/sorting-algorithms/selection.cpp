#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        cout << "After pass " << i + 1 << endl;
        for (int k = 0; k < n; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;

        if (min != i)
        {
            swap(a[min], a[i]);
        }
    }
}

int main()
{
    int arr[] = {3,6,7,5,1,6,4}, len;
    len = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, len);
    cout << "Final array" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}