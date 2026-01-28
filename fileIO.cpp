#include<bits/stdc++.h>
using namespace std;

/* step1:define stream
  step2:perform operation
  step3:file closing     */

int main(){
  string str1,str2; 
  cout<<"Enter string: ";
  getline(cin,str1);

  // Write/insertion operation-----
  ofstream out("abc.txt");
  out<<str1;
  out.close();

  // Read/extraction operation-----
  ifstream hin("abc.txt");
  getline(hin,str2);
  out.close();

  cout<<str2;

  return 0;
}