#include <iostream>
using namespace std;

void show(int arr[],int s,int n){
  if(n==s)  return;
  cout<<arr[n]<<endl;
  show(arr,s,n+1);
  cout<<arr[n]<<endl;
}

//print array for bs
void printarr(int arr[],int s,int e){
  for(int i=s; i<=e; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}

//binary search
bool bs(int arr[],int s,int e,int k){
  printarr(arr,s,e);
  if(s>e)  return false;      //base case  
  
  int mid=s+(e-s)/2;
  if(arr[mid]==k)  return true;

  return arr[mid]<k? bs(arr,mid+1,e,k) :  bs(arr,s,mid-1,k);
}

//linear search
bool ls(int *arr,int size,int key){
  if (size == 0)   return false;
  return arr[0] == key? true : ls(arr+1, size-1, key);
}

//sorting
bool isSorted(int *arr, int size){
  if (size == 0 || size == 1)  return true;
  return arr[0] > arr[1]? false : isSorted(arr + 1, size - 1);
}

//total sum
int total(int arr[],int n){
  if(n == 0)  return 0;
  return arr[n-1] + total(arr,n-1); 
}

//main func
int main(){
  int arr[7] = {1,2,3,4,5,6,7};
  int k = 5;
  
  show(arr,7,0);
  cout<<"total sum of array is: "<<total(arr,7);
  
  // ls(arr,7,k)?   cout<<"present":cout<<"absent";

  // bs(arr,0,6,k)?  cout<<"present":cout<<"absent"; 

  // isSorted(arr,7)?   cout<<"Sorted":cout<<"Unsorted";

  return 0;
}