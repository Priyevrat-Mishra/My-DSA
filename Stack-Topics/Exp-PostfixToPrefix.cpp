#include <bits/stdc++.h>
using namespace std;

string solve(string a, string b, char op){
  string s = "";
  s.push_back(op);
  s+=a;
  s+=b;
  return s;
}

int main(){
  string s = "79+4*8/3-";
  stack<string> val;
  for (int i = 0; i < s.length(); i++){
    if (s[i] >= 48 && s[i] <= 57)  val.push(to_string(s[i] - 48));
    else{
      string b=val.top();
      val.pop();
      string a = val.top();
      val.pop();
      val.push(solve(a,b,s[i]));
    }
  }
  cout<<val.top();
  return 0;
}