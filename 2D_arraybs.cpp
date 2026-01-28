#include<bits/stdc++.h>
using namespace std;

//binary search
void bs(int arr[][3],int target,int row,int col){
    int start = 0;
    int end = (row*col)-1;
    int mid = start+(end-start)/2;
    while(start <= end){
        int x = arr[mid/col][mid%col];
        if(x == target){
            cout<<"found";
            break;
        }
        if(x > target)   end = mid-1;
        else   start = mid+1;
        x = arr[mid/col][mid%col];
    }
cout<<endl;
}

// rotate matrix 90 degree
void rotateMatrix(int arr[][3], int n){
    // Transpose the matrix
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            swap(arr[i][j], arr[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n / 2; ++j){
            swap(arr[i][j], arr[i][n - 1 - j]);
        }
    }
}

// print array
void printarr(int arr[][3]){
    for(int i=0; i<3; i++){
        for(int k=0; k<3; k++){
            cout<<arr[i][k]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[3][3]= {1,2,3,4,5,6,7,8,9};
    printarr(arr);
    int target;
    cout<<"enter target: ";
    cin>>target;
    cout<<endl;
    bs(arr,target,3,3);
    rotateMatrix(arr,3);
    printarr(arr);
    return 0;
}