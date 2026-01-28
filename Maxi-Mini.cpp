#include<iostream>
using namespace std;

int getmax(int arr[], int n){
    int maxi =INT_MIN;
    for (int i=0;i<n;i++){
        //  if(arr[i]>max){
        //  max=arr[i]; }
        maxi=max(maxi,arr[i]);
    } 
    return maxi;
}

int min(int arr[], int n){
    int min =INT_MAX;
    for (int i=0;i<n;i++)
        if(arr[i]<min)
            min=arr[i];
    return min;
}

bool search(int arr[],int size,int key){
    for(int i=0;i<size;i++)
        if(arr[i]==key)
            return i;
    return 0;
}

int main(){
    int size,arr[100],key;
    cout<<"enter array size: ";
    cin>>size;
    cout<<"enter elements: ";
    for (int i=0; i<size; i++)
        cin>>arr[i];

    cout<<"element to be searched:";
    cin>>key;
    cout<<"maximum is"<<getmax(arr,size)<<endl;
    cout<<"minimum is"<<min(arr,size)<<endl;

    bool found=search(arr,size,key);
    if(found)  cout<<"no. is present";
    else  cout<<"no. is absent";  

    return 0;
}
