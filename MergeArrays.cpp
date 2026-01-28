#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>&a, vector<int>&b){
  int m=a.size(),n=b.size();
  vector<int> v(m+n);
  int i = 0, j = 0, k = 0;
  while(i<=n && j<=m){
    if(a[i]<b[j]) v[k++]=a[i++];
    else v[k++]=b[j++];
  }
  while(i<=n) v[k++]=a[i++];
  while(j<=m) v[k++]=b[j++];
  return v;
}

int main(){
  vector<int> a = {1,2,5,6};
  vector<int> b = {2,4,7,8};
  vector<int> c;
  vector<int>v=merge(a,b);
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
  return 0;
}

