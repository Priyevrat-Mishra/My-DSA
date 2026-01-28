#include<bits/stdc++.h>
using namespace std;

// Function to print a subset
void printSubset(const vector<int>& subset) {
    cout << "{ ";
    for (int value : subset)  cout << value << " ";
    cout << "}" <<endl;
}

// Recursive function to generate all subsets
void generateSubsets(const vector<int>& set, vector<int>& subset, int index) {
  // Base case: all elements have been considered, print the current subset 
  if (index == set.size()){
    printSubset(subset);
    return ;
  }

  // Exclude the current element and move to the next
  generateSubsets(set, subset, index + 1);

  // Include the current element in the subset and move to the next
  subset.push_back(set[index]);
  generateSubsets(set, subset, index + 1);

  // Backtrack to remove the current element from the subset
  subset.pop_back();
}

int main() {
  vector<int> set = {1, 2, 3};
  vector<int> subset;

  cout << "All subsets are: "<<endl; 
  generateSubsets(set, subset, 0);

  return 0;
}