#include<bits/stdc++.h>
using namespace std;

int digit(int n){
    int count=0;
    while(n){
        count++;
        n/=10;     }
    return count;
}

bool armstrong(int num,int digit){

    int n=num,ans=0, rem;
    while(n){
        rem=n%10;
        n/=10;
        ans=ans+pow(rem,digit); 
    }
    if(ans==num)  return true;
    else  return false;
}

char convert(char name){
    char ans=name-'a'+'A';
    return ans;
}

int main(){
    int num;
    cout<<"enter no.:";
    cin>>num;
    int digits = digit(num);
    cout<<armstrong(num,digits)<<endl;

    char name;
    cout<<"enter charater:";
    cin>>name;
    cout<<convert(name);
    return 0;
}  