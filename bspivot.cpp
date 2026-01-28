#include<iostream>
using namespace std;

int pivot(int arr[],int n ){
    // int s=0,e=n-1;
    // while(s<e){
    //     int mid = s+(e-s)/2;
    //     if(arr[mid] >= arr[0])  s = mid+1;
    //     else  e = mid;
    // }
    // return s;
        int l = 0, h = n - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (arr[m] > arr[m + 1])   h = m ;
            else   l = m + 1;
        }
        return l;
}

int main(){
    int arr[10]= {11,13,15,17,19,20,4,5,8,9};
    int result= pivot(arr,10);
    cout<<"pivot:"<<result<<endl;
    return 0;
}
