#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, char op){
  if (op == '+')  return a + b;
  else if (op == '-')  return a - b;
  else if (op == '*')  return a * b;
  else  return a / b;
}

int main(){
  string s = "79+4*8/3-";
  stack<int> val;
  for (int i = 0; i < s.length(); i++){
    if (s[i] >= 48 && s[i] <= 57)  val.push(s[i] - 48);
    else{
      int b=val.top();
      val.pop();
      int a = val.top();
      val.pop();
      val.push(solve(a,b,s[i]));
    }
  }
  cout<<val.top();
  return 0;
}