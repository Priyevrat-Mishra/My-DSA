#include <bits/stdc++.h>
using namespace std;

void show(int arr[], int n){
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void insertionSort(int arr[], int n){
  for (int i = 1; i < n; i++){
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1])
      swap(arr[j--], arr[j - 1]);
  }
}

int main(){
  int arr[] = {6, 4, 5, -3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << " Before sorting: ";
  show(arr, n);
  insertionSort(arr, n);
  cout << " After sorting: ";
  show(arr, n);

  return 0;
}