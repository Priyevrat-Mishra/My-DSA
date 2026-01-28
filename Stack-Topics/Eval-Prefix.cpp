#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, char op){
  if (op == '+')  return a + b;
  else if (op == '-')  return a - b;
  else if (op == '*')  return a * b;
  else  return a / b;
}

int main(){
  string s = "-/*+79483";
  stack<int> val;
  for (int i = s.length() - 1; i >= 0; i--){
    if (s[i] >= 48 && s[i] <= 57)  val.push(s[i] - 48);
    else{
      int a = val.top();
      val.pop();
      int b = val.top();
      val.pop();
      val.push(solve(a, b, s[i]));
    }
  }
  cout << val.top();
  return 0;
}