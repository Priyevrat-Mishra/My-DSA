#include <bits/stdc++.h>
using namespace std;

void sieve(int x){
  vector<int> sieve(x + 1, 1);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i <= sqrt(x); i++)
    if (sieve[i] == 1)
      for (int j = i * i; j <= x; j += i)  sieve[j] = 0;
      
  for (int i = 2; i <= x; i++)
    if (sieve[i] == 1)  cout << i << " ";
  cout<<endl;
}

int main(){
  int n = 21;
  cout << "Primes upto " << n << " is: ";
  sieve(n);

  return 0;
}