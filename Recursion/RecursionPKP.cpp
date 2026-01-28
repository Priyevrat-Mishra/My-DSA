#include <bits/stdc++.h>
using namespace std;

//Mapping of digits to letters->0  1     2      3      4      5      6      7       8      9
const vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

// Recursive function to generate combinations
void generateCombo(const string& digits, int index, string current, vector<string>& result) {
  // Base case: if the current combination is complete
  if(index == digits.size()){
    result.push_back(current);
    return;
  }
  
  // Get the characters corresponding to the current digit
  string letters = keypad[digits[index] - '0'];
  
  // Loop through all the characters and recurse
  for (char letter : letters)  
    generateCombo(digits, index+1, current + letter, result);
}

// Function to initiate the combination generation
vector<string> letterCombo(const string &digits) {
  vector<string> result;
  if(!digits.empty()) generateCombo(digits, 0, "", result);
  return result;
}

// Main function to test the implementation
int main() {
  string digits;
  cout << "Enter the digits: ";
  cin >> digits;

  cout << "The combinations are:" << endl;
  for(const string& combination : letterCombo(digits))  cout << combination << endl;

  return 0;
}
