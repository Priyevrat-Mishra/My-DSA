#include <bits/stdc++.h>
using namespace std;

void show(vector<int> v){
  for (int i : v)
    cout << i << " ";
  cout << endl;
}

vector<int> slidingWinMax(vector<int>v,int k){
  deque<int> d;
  vector<int> ans;
  for (int i = 0; i < k - 1; i++){
    while (!d.empty() && v[i] > v[d.back()])
      d.pop_back();
    d.push_back(i);
  }

  for (int i = k - 1; i < v.size(); i++){
    while (!d.empty() && v[i] > v[d.back()])
      d.pop_back();
    d.push_back(i);
    if (d.front() <= i - k)
      d.pop_front();
    ans.push_back(v[d.front()]);
  }
  return ans;
}

int main(){
  vector<int> v = {4, 3, 7, 5, 2, 3, 1, 2, 8, 7};
  int k = 4;
  show(v);
  v = slidingWinMax(v,k);
  show(v);
  return 0;
}