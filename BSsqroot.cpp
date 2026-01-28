#include<iostream>
using namespace std;

long long int sqroot(int n){
    int s=0,e=n;
    long long int mid=s+(e-s)/2, ans=-1;
    while(s<=e){
        long long int square = mid*mid;
        if(square == n)    return mid;
        else if(square < n){
            ans= mid;
            s=mid+1;
        }
        else    e=mid-1;
        mid = s+(e-s)/2;
    }
    return ans;
}

double precision(int n ,int precision, int result){
    double factor=1,ans=result;
    for(int i=0;i<precision; i++){
        factor/=10;
        for(double j=ans; j*j<n; j+=factor){
            ans=j;
        }
    }return ans;
}

int main(){
    int n;
    cout<<"enter no.: "<<endl;
    cin>>n;
    int result=sqroot(n);
    cout<<precision(n,3,result);
    return 0;
}
