#include <bits/stdc++.h>
using namespace std;

void show(deque<int>&q){
  for (int i : q)  cout << i << " ";
  cout << endl;
}

int main(){
  deque<int> q;
  q.push_front(1);
  q.push_front(2);
  q.push_front(3);
  q.push_back(4);
  q.push_back(5);
  show(q);

  return 0;
}