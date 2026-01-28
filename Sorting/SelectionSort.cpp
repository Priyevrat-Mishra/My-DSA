#include<iostream>
using namespace std;

void show(int arr[], int n){
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(int *arr,int size){
    for (int i = 0; i < size - 1; ++i){
        int index = i;
        for (int j = i + 1; j < size; ++j)
            if (arr[j] < arr[index])
                index = j;
        swap(arr[i], arr[index]);
    }
}

int main(){
    int arr[5]= {6,8,4,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Before sorting: ";
    show(arr,n);

    selectionSort(arr,5);
    cout << "After sorting: ";
    show(arr,n);

    return 0;
}