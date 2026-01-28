#include <iostream>
using namespace std;

// decimal to binary
int db(int num){
  int rem, ans = 0, mul = 1;
  while (num > 0){
    rem = num % 2;
    num /= 2;
    ans += rem * mul;
    mul *= 10;
  }
  return ans;
}

// binary to decimal
int bd(int num){
  int rem, ans = 0, mul = 1;
  while (num > 0){
    rem = num % 10;
    num /= 10;
    ans += rem * mul;
    mul *= 2;
  }
  return ans;
}

// reverse the number
int reverse(int num){
  int rem, ans = 0, mul = 1;
  while (num != 0){
    int rem = num % 10;
    ans = ans * 10 + rem;
    num /= 10;
  }
  return ans;
}

int main(){
  cout<<"enter no:";
  int n;
  cin >> n;
  cout << bd(n) << endl;
  // cout << db(n) << endl;
  cout<<reverse(n)<<endl;
  return 0;
}
