#include<iostream>
using namespace std;
int linearsearch(int arr[],int size,int element){
    for(int i=0; i<size; i++)
        if(arr[i]==element)
            return i;
    return-1;
}

int binarysearch(int *arr, int size,int element){
    int low = 0,high = size-1;
    while(low <= high){
        int mid = low + (high-low)/2;   //mid=(low+high)/2
        if(arr[mid] == element)    return mid;
        else if(arr[mid] < element)    low=mid+1;
        else    high=mid-1;
    }
    return -1;
}

int lastocc(int arr[], int n, int element){
    int index = -1;
    for (int i = n-1; i >= 0; i--){
        if (arr[i] == element){
            index = i;
            break;
        }
    }
    return index;
}

int main(){
    int arr[]= {44,55,66,66,77,88,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    int element;
    cout<<"enter the element from array: ";
    cin>>element;
    cout<<"Binaryserach: "<<binarysearch(arr,n,element)<<endl;
    cout<<"Linearsearch: "<<linearsearch(arr,n,element)<<endl;
    cout<<"Last occurence: "<<lastocc(arr,n,element);
    return 0;
}
