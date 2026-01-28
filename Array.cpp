#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>& arr,int m){
  int start=m+1,end=arr.size()-1;
  while(start<=end)
    swap(arr[start++],arr[end--]);
}

int main(){
  int size,m;
  cout<<"enter size of array: ";
  cin>>size;
  vector<int> arr(size);
  cout<<"enter the elements: ";
  for(int i=0; i<size; i++)   cin>>arr[i];

  cout<<"enter the value of m: ";
  cin>>m;

  cout<<"entered elements: ";
  for(int i=0; i<size;i++)
  cout<<arr[i]<<endl;

  cout<<"reverse array:"<<endl;
  reverse(arr,m);
  for(int i=0; i<arr.size();i++)
  cout<<arr[i]<<" ";

  return 0;
}