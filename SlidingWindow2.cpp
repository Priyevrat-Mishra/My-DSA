// Q: First negative no. in every window of size k
#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v = {2, 3, 4, 4, -7, -1, 4, -2, 6};
  for (int z : v)  cout << z << " ";
  cout << endl;
  int n = v.size();
  int k = 3, p = -1;
  vector<int> ans(n - k + 1, 1);
  for (int i = 0; i < k; i++)
    if (v[i] < 0){
      p = i;
      break;
    }
  ans[0] = (p == -1) ? 1 : v[p];
  int i = 1, j = k;
  while (j < n){
    if (p >= i)   ans[i] = v[p];
    else{
      for (p = i; p <= j; p++)
        if (v[p] < 0)   break;
      ans[i] = v[p];
    }
    i++;
    j++;
  }
  for (int z : ans)   cout << z << " ";
  return 0;
}