#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n<=1)    return 1;
    return n*fact(n-1);
}

int pow(int b,int n){
    if(n==0)    return 1;
    return b*pow(b,n-1);
}

int  fibo(int n) {
  if (n <= 1)   return n;
  return fibo(n-1) + fibo(n-2);
}

void print(int n){
  if(n==0)  return ;
  cout<<n<<" ";
  print(n-1);
  cout<<n<<" ";
}

int main(){
    int a,b;
    cout<<"enter base and power:";
    cin >> b >>a;
    cout<<"factorial is:"<<fact(b)<<endl;
    cout<<"fibo no. at term is:"<<fibo(b)<<endl;
    cout<<"power is:"<<pow(b,a)<<endl;
    cout<<"print is:";
    print(a);

return 0;
}