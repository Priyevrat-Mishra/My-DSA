#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s){   //TC = O(nlogn)
  stack<char> st;
  st.push(s[0]);
  for (int i = 1; i < s.length(); i++)
    if (s[i] != st.top())  st.push(s[i]);

  s="";
  while (st.size() > 0){
    s += st.top();
    st.pop();
  }
  reverse(s.begin(), s.end());
  return s;
}

string removeDuplicates1(string s){  //TC = O(n)
  stack<char> st;
  st.push(s[0]);
  for (int i = s.length(); i >=0; i--)
    if (s[i] != st.top())  st.push(s[i]);

  s="";
  while (st.size() > 1){
    s += st.top();
    st.pop();
  }
  return s;
}

int main(){
  string s = "aaabbcddaabffg";
  cout << s << endl << removeDuplicates1(s);

  return 0;
}
