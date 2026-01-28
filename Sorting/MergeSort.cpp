#include <iostream>
using namespace std;

// merge func
void merge(int *arr, int s, int e){
  int m = s + (e - s) / 2;

  int len1 = m - s + 1, len2 = e - m;
  int *a = new int[len1];
  int *b = new int[len2];

  // copy values
  for (int i = 0; i < len1; i++)  a[i] = arr[s + i];
  for (int i = 0; i < len2; i++)  b[i] = arr[m + 1 + i];

  // merge sorted sub-arrays
  int i = 0, j = 0, k = s;
  while (i < len1 && j < len2){
    if (a[i] <= b[j])  arr[k++] = a[i++];
    else  arr[k++] = b[j++];
  }
  while (i < len1)  arr[k++] = a[i++];
  while (j < len2)  arr[k++] = b[j++];

  delete[] a;
  delete[] b;
}

// merge sort func
void mergesort(int *arr, int s, int e){
  if (s >= e)  return;
  int m = s + (e - s) / 2;
  mergesort(arr, s, m);
  mergesort(arr, m + 1, e);
  merge(arr, s, e);
}

int main(){
  int arr[5] = {13, 2, 5, 9, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted array : ";
  for (int i : arr)  cout << i << " ";

  mergesort(arr, 0, n - 1);
  cout << "\nSorted array : ";
  for (int i : arr)  cout << i << " ";

  return 0;
}
/*
 in case of vector, we pass vector by reference for no errors i.e. 
  void merge(vector<int>&v,int s,int e)
  void mergesort(vector<int>&v,int s,int e)
*/