#include <bits/stdc++.h>
using namespace std;

// normal traversing for previous greater index
int main(){
  vector<int> v = {100,80,60,81,70,60,75,85};
  for (int x : v)  cout << x << " ";
  cout << endl;

  stack<int> st;
  vector<int> z(v.size(), -1);      //pop mark push
  for (int i = 0; i < v.size(); i++){
    while (!st.empty() && v[i] >= v[st.top()])  st.pop();
    if (!st.empty())  z[i] = st.top();
    z[i] = i - z[i];
    st.push(i);
  }

  for (int x : z)  cout << x << " ";
  return 0;
}