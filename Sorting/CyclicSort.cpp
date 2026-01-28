#include <bits/stdc++.h>
using namespace std;

void  cyclicSort(vector<int> &a){
  int i = 0;
  while (i < a.size()){
    int rdx = a[i]-1;         // right index
    if (a[i] == a[rdx])  i++;
    else  swap(a[i], a[rdx]);
  }
}

int  cs(vector<int> &a){
  int i = 0;
  while (i < a.size()){
    int rdx = a[i];         // right index
    if (a[i] == a[rdx])  return a[i];
    else  swap(a[i], a[rdx]);
  }
  return 0;
}

int main(){
  vector<int> v = {5, 1, 6, 3, 4,7, 2, 7};
  cout << "unsorted array: ";
  for (int z : v)  cout << z << " ";

  cout << "\nsorted array: "<<cs(v);
  // cyclicSort(v);
  // for (int z : v)  cout << z << " ";

  return 0;
}
/*
if unique elements start from 0, rdx = a[i];
if unique elements start from 1, rdx = a[i]-1;
in case of duplicate elements, return a[i] and change datatype and rdx = a[i]; 
*/