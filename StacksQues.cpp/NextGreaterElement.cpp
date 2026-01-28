#include <bits/stdc++.h>
using namespace std;

// reverse traversing for next greater element
int main(){
  vector<int> v = {3, 1, 2, 5, 6, 2, 3};
  for (int x : v)  cout << x << " ";
  cout << endl;

  stack<int> st;
  vector<int> z(v.size(), -1);  //pop mark push
  for (int i = v.size() - 1; i >= 0; i--){
    while (!st.empty() && v[i] >= st.top() )  st.pop();
    z[i] = st.empty() ? -1 : st.top();
    st.push(v[i]);
  }

  for (int x : z)  cout << x << " ";
  return 0;
}
// for circular traversing
// in place of v[i], use v[i%n]
// in place of size, use 2*size-1
// also put ternary condition in if(i<size) 
