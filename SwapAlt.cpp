#include<iostream>
using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++)  cout<<arr[i]<<" ";
}

void swapalt(int arr[],int size){
    for(int i=0;i<size;i+=2)  if(i+1<size)  swap(arr[i],arr[i+1]);
}

int main(){
int even[6]={1,2,3,4,5,6};
cout<<"array elements: ";
printarr(even,6);
cout<<"\nswapping alternatively: ";    
swapalt(even,6);
printarr(even,6);
return 0;
}  