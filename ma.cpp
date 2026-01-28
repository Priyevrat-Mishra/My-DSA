#include<iostream>
using namespace std;

int main(){
    int arr[6]= {44,55,66,77,88,99};
    int start=0, end=5;
    while(start<end)
        swap(arr[start++],arr[end--]);
    for(int i=0; i<6; i++)
        cout<<arr[i]<<" ";

    int n;
    cout<<"enter no.:";
    cin>>n;
    int ar[10];
    ar[0]=0;
    ar[1]=1;
    for(int i=2; i<=n-1; i++)
        ar[i]=ar[i-1]+ar[i-2];
    cout<<ar[n-1]<<" ";

    return 0;
}
