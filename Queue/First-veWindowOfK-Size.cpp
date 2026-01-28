#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeWindow(int arr[],int n, int k){
  queue<int> q;
  vector<int> v;
  for (int i = 0; i < n; i++)  if (arr[i] < 0)  q.push(i);
  int i = 0;
  while (i <= n-k){
    while (!q.empty() && q.front() < i)  q.pop();
    if (q.empty() || q.front() >= i + k)  v.push_back(0);
    else  v.push_back(arr[q.front()]);
    i++;
  }
  return v;
}

int main(){
  int arr[] = {3, -4, -7, 30, 7, -9, 2, 1, 6, -1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  vector<int>v = firstNegativeWindow(arr,n,k);
  for (int z : arr)  cout << z << " ";
  cout << endl;
  for (int z : v)  cout << z << " ";

  return 0;
}