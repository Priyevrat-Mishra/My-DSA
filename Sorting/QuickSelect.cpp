#include <iostream>
using namespace std;

// partititon function
int part(int arr[], int s, int e){
  int p = arr[s];
  int count = 0;
  for (int i = s + 1; i <= e; i++)
    if (arr[i] <= p)  count++;

  // place pivot at right index
  int pindex = s + count;
  swap(arr[pindex], arr[s]);

  // condition
  int i = s, j = e;
  while (i < pindex && j > pindex){
    while (arr[i] <= p)  i++;
    while (arr[j] > p)  j--;
    if (arr[i] > p && arr[j] < p)  swap(arr[i], arr[j]);
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

int quickselect(int arr[], int s, int e, int k){
  int p = part(arr, s, e);
  if (p  == k)  return arr[p];
  else if (p  > k) return quickselect(arr, s, p - 1, k);
  else   return quickselect(arr, p + 1, e, k);
}

int main(){
  int arr[] = {15,13,12,11,14,-16};
  int n = sizeof(arr) / sizeof(arr[0]);

  quicksort(arr, 0, n - 1);
  cout << "sorted array: ";
  for (int a : arr)  cout << a << " ";

  int k = 3;
  cout << endl<<k<<"th smallest: "<< quickselect(arr, 0, n - 1, k-1);
  cout << endl<<k<<"th largest: "<< quickselect(arr, 0, n - 1, n-k);

  return 0;
}
/*
for kth smallest in quick-select func call, we can reduce k by n i.e. n-k;
for kth smallest in quick-select func call, we can reduce k by -1 i.e. k -1,
or during quick-select func, we can add 1 to the pindex;

*/
