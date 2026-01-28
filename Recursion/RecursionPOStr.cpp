#include <bits/stdc++.h>
using namespace std;

// Function to generate permutations
void generatePermutations(vector<int>& arr, int index, vector<vector<int>>& result){
  if (index == arr.size()){
    result.push_back(arr);
    return;
  }

  for (int i = index; i<arr.size(); ++i){
    swap(arr[index], arr[i]);
    generatePermutations(arr, index+1, result);
    swap(arr[index], arr[i]); // Backtrack
  }
}

// Function to initiate permutation generation
vector<vector<int>> permute(vector<int> &arr){
  vector<vector<int>> result;
  generatePermutations(arr, 0, result);
  return result;
}

// Main function to test the implementation
int main(){
  vector<int> arr = {1, 2, 3};

  cout << "The permutations are:" << endl;
  for (const auto &perm : permute(arr)){
    for (int num : perm){
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
