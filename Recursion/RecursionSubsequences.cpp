#include <bits/stdc++.h>
using namespace std;

void generateSubsequences(string input,string output,vector<string> &result) {
  //Base case: if i/p string is empty, add current o/p to result
  if (input.empty()) {
    result.push_back(output);
    return ;
  }
  
  //Recursive case: exclude the first character and recurse
  generateSubsequences(input.substr(1), output, result);
  
  // Recursive case: include the first character and recurse
  generateSubsequences(input.substr(1), output + input[0], result);
}

int main() {
  string str = "abc";
  vector<string> subsequences;
  generateSubsequences(str, "", subsequences);
  cout <<"Subsequences of "<<str<<" are:";
  for (const auto &value : subsequences) cout << value <<endl;
  
  return 0;
}