#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v = {7, 11, 2, 15, 8, 4, 9, 3, 6};
  int k = 3;
  int sum = 0;
  int maxidx = -1;
  int maxSum = INT_MIN;

  // traversal for sum of first k elements
  for (int i = 0; i < k; i++)  sum += v[i];
  maxSum = sum;
  
  // sliding window technique
  int i = 1, j = k;
  while (j < v.size()){
    sum += v[j] - v[i - 1];
    if (maxSum < sum){
      maxSum = sum;
      maxidx = i;
    }
    i++,j++;
  }
  cout << maxSum << " from Index " << maxidx;

  return 0;
}
// for(int i=0;i<=n-k;i++){  //tc=o(n*n)
//   int sum=0;
//   for(int j=i;j<i+k;j++)sum+=v[j];
//   if(maxSum<sum){
//     maxSum=sum;
//     maxidx=i;
//   }
// }