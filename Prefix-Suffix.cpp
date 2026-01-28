#include <bits/stdc++.h>
using namespace std;

void show(vector<int> &v){
  for (int z : v)  cout << z << " ";
}

void psum(vector<int> &v){
  for (int i = 1; i < v.size(); i++)  v[i] += v[i - 1];
}

void pprod(vector<int> &v){
  for (int i = 1; i < v.size(); i++)  v[i] *= v[i - 1];
}

void ssum(vector<int> &v){
  for (int i = v.size() - 2; i >= 0; i--)  v[i] += v[i + 1];
}

void sprod(vector<int> &v){
  for (int i = v.size() - 2; i >= 0; i--)  v[i] *= v[i + 1];
}

int main(){
  vector<int> v = {7, 3, 1, 6, 5, 6};
  cout << "prefix sum : ";
  psum(v);
  // pprod(v);
  // show(v);

  vector<int> m = {2, 1, -1, 1};
  cout << "\nsuffix sum : ";
  ssum(m);
  // sprod(m);
  // show(m);

  int n = v.size();
  vector<int> p(n), s(n);
  p[0] = v[0], s[n - 1] = v[n - 1];
  for (int i = 1; i < n; i++)
    p[i] = p[i - 1] + v[i];

  for (int i = n - 2; i >= 0; i--)
    s[i] = s[i + 1] + v[i];

  for (int i = 0; i < n; i++)
    if (p[i] == s[i])  cout << i;

  return 0;
}