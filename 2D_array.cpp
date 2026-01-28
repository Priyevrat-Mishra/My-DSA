#include <bits/stdc++.h>
using namespace std;

// linear search
bool search(int arr[][3], int target){
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (arr[i][j] == target)
        return true;
  return false;
}

// print row wise sum
void rsum(int arr[][3], int n, int m){
  for (int i = 0; i < n; i++){
    int sum = 0;
    for (int j = 0; j < m; j++)
      sum += arr[i][j];
    cout << "sum of row " << i << " is " << sum << endl;
  }
}

// largest row sum
int largestrsum(int arr[][3], int n, int m){
  int maxi = INT_MIN;
  int index = -1;
  for (int i = 0; i < n; i++){
    int sum = 0;
    for (int j = 0; j < m; j++)
      sum += arr[i][j];
    if (sum > maxi){
      maxi = sum;
      index = i;
    }
  }
  cout << "maximum sum is " << maxi << " at index " << index << endl;
  return maxi;
}

// print column wise sum
void csum(int arr[][3], int n, int m){
  for (int i = 0; i < m; i++){
    int sum = 0;
    for (int j = 0; j < n; j++)
      sum += arr[j][i];
    cout << "sum of column " << i << " is " << sum << endl;
  }
}

int main(){
  int arr[3][3];
  int n = 3, m = 3;

  // taking input
  cout << "Enter the elements: ";
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> arr[i][j];

  // printing the array
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }

  int target;
  cout << "enter target: " << endl;
  cin >> target;
  if (search(arr, target))  cout << "Element found" << endl;
  else  cout << "Element not found" << endl;

  rsum(arr, n, m);
  csum(arr, n, m);
  largestrsum(arr, n, m);
  return 0;
}