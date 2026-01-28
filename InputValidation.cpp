#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  // cout<<"enter no:";
  // method : 1--------
  // while(!(cin>>n)){
  //   cout << "try again: ";
  //   cin.clear();
  //   cin.ignore(10000,'\n');
  // }
  // cout << "you entered: " << n;

  // method : 2--------
  do{
    cout << "enter no: ";
    cin >> n;
  } while(n < 0 || n > 10);
  cout << "you entered: " << n;

  return 0;
}