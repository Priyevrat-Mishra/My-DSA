#include <bits/stdc++.h>
using namespace std;

void rotate(int *arr, int n, int k){
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[(i + k) % n] = arr[i];
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

void print(int *arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Array Before Rotation:";
    print(arr, n);
    rotate(arr, n, k);
    cout << "Array After Rotation:";
    print(arr, n);
    return 0;
}
