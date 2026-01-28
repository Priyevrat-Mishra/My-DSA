#include <iostream>
using namespace std;

int main(){
  int num, rem = 0, ans = 0;
  cout << "enter no.:";
  cin >> num;
  while (num > 9){
    while (num != 0){
      rem = num % 10;
      num /= 10;
      ans += rem;
    }
    num = ans;
  }
  cout << num;
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//  	int T;
//  	string n;
//  	cout<<"test case:"<<endl;
//  	cin>>T;
//  	cout<<T<<endl;
//  	for(int i=0;i<T;++i)
//  		cin>>n;

// 	for(int i=0;i<T;i++)
// 	cout<<n[0]<<" "<<n[1]<<endl;
// 	return 0;
// }
