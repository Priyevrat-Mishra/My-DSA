#include <bits/stdc++.h>
using namespace std;

bool isbalance(string s){
  if (s.length() % 2 != 0)  return false;
  stack<char> st;
  for (int i = 0; i < s.length(); i++){
    if (s[i]=='(' || s[i]=='[' || s[i]=='{')  st.push(s[i]);
    else{
      if (st.empty())  return false;
      else  st.pop();
    }
  }
  return st.empty();
}

int main(){
  string s = "()[{}]";
  cout << isbalance(s);

  return 0;
}