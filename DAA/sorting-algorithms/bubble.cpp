#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void bubblesort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag++;
            }
        }
        cout << "After pass " << i+1 << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {2,1,8,3,6,9,12,4,7,10}, len;
    len = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, len);
    cout << "Final array" << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}