#include <iostream>
using namespace std;

// partititon function
int part(int arr[], int s, int e){
  int p = arr[s];
  int count = 0;
  for (int i = s + 1; i <= e; i++)  if (arr[i] <= p)  count++;

  // place pivot at right index
  int pindex = s + count;
  swap(arr[pindex], arr[s]);

  // condition
  int i = s, j = e;
  while (i < pindex && j > pindex){
    while (arr[i] < p)  i++;
    while (arr[j] > p)  j--;
    if (i < pindex && j > pindex)  swap(arr[i], arr[j]);
  }
  return pindex;
}

// quicksort function
void quicksort(int arr[], int s, int e){
  if (s >= e)  return;
  int p = part(arr, s, e);
  quicksort(arr, s, p - 1);
  quicksort(arr, p + 1, e);
}

int main(){
  int arr[7] = {1, 5, 1, 2, 3, 9, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  quicksort(arr, 0, n - 1);
  cout << "sorted array: ";
  for (int a:arr)  cout << a << " ";
  return 0;
}

/*
 in case of vector, we pass vector by reference for no errors i.e.
  void part(vector<int>&v,int s,int e)
  void quicksort(vector<int>&v,int s,int e)
*/