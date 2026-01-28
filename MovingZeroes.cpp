#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n){
    for (int i = 0; i < n; i++)    cout << arr[i] << " ";
    cout << endl;
}

void moveZeroes(int arr[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)    swap(arr[i], arr[count++]);
}

int main(){
    int arr[] = {1, 0, 6, 0, 3, 0, 4, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    moveZeroes(arr, n);
    print(arr, n);

    return 0;
}