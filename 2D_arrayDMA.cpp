#include <bits/stdc++.h>
using namespace std;

int gsum(int *arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int main(){
    // new int;
    int n;
    cout << "enter array size: ";
    cin >> n;
    //creating 2d array from heap
    //case1:square matrix
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout<< arr[i][j]<<" ";
        cout<<endl;
    }
    

    return 0;
}