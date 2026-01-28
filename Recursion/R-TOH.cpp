// Tower of Hanoi
#include <bits/stdc++.h>
using namespace std;

//in hanoi there are 3 terms : source, helper, destiny
//we always go from source with helper to destiny
void hanoi(int n, char a, char b, char c){
  if (n == 0)  return;
  hanoi(n - 1, a, c, b);
  cout << a << " -> " << c << endl;
  hanoi(n - 1, b, a, c);
}

int main(){
  int n = 3;
  hanoi(n, 'A', 'B', 'C');

  return 0;
}