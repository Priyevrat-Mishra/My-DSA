#include<iostream>
using namespace std;

void show(int arr[], int n){
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
}

void bubblesort(int *arr,int size){
    for(int i=0; i<size-1; i++){
        bool swapped = false;
        for(int j=0; j<size-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped)  break;
    }
}

int main(){
    int arr[]= {10,1,7,16,14,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Before sorting: ";
    show(arr,n);
    bubblesort(arr,n);
    cout << "After sorting: ";
    show(arr,n);
    return 0;
}