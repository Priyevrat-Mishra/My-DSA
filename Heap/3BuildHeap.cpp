#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int size){
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// step-down
void HeapifyMax(int arr[], int size, int idx){
  int maxi = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < size && arr[maxi] < arr[left])
    maxi = left;
  if (right < size && arr[maxi] < arr[right])
    maxi = right;

  if (maxi != idx){
    swap(arr[maxi], arr[idx]);
    HeapifyMax(arr, size, maxi);
  }
}

void HeapifyMin(int arr[], int size, int idx){
  int mini = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < size && arr[mini] > arr[left])
    mini = left;
  if (right < size && arr[mini] > arr[right])
    mini = right;

  if (mini != idx){
    swap(arr[mini], arr[idx]);
    HeapifyMin(arr, size, mini);
  }
}

void BuildHeap(int arr[], int n){
  for (int i = n / 2 - 1; i >= 0; i--)
    HeapifyMax(arr, n, i);
}

// TC = O(nlogn)    SC = O(1)
void HeapSort(int arr[], int n){
  for(int i = n-1; i > 0; i--){
    swap(arr[i], arr[0]);
    HeapifyMax(arr, i, 0);
  }
}

int main(){
  int arr[] = {10, 2, 8, 9, 5, 13, 14, 11, 70};
  int n = sizeof(arr) / sizeof(arr[0]);
  BuildHeap(arr, n);
  print(arr, n);
  HeapSort(arr, n);
  cout<<"Heap Sort: ";
  print(arr, n);

  return 0;
}