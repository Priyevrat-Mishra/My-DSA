#include <bits/stdc++.h>
using namespace std;

string solve(string a, string b, char op){
  string s = "";
  s+=a;
  s+=b;
  s.push_back(op);
  return s;
}

int main(){
  string s = "-/*+79483";
  stack<string> val;
  for (int i = s.length() - 1; i >= 0; i--){
    if (s[i] >= 48 && s[i] <= 57)  val.push(to_string(s[i] - 48));
    else{
      string a = val.top();
      val.pop();
      string b = val.top();
      val.pop();
      val.push(solve(a, b, s[i]));
    }
  }
  cout << val.top();
  return 0;
}