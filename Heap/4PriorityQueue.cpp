#include<bits/stdc++.h>
using namespace std;

int main(){
  cout<<"Max Heap Priority Queue--------\n";
  priority_queue<int>p;
  p.push(10);
  p.push(20);
  p.push(11);
  p.push(18);
  p.push(15);
  cout<<"Size : "<<p.size()<<endl;
  while(!p.empty()){
    cout<<p.top()<<" ";
    p.pop();
  }

  /* Declaration is different for min and max heap, rest all will be same */

  cout<<"\nMin Heap Priority Queue--------\n";
  priority_queue<int, vector<int>, greater<int>>pq;
  pq.push(10);
  pq.push(20);
  pq.push(11);
  pq.push(18);
  pq.push(15);
  cout<<"Size : "<<pq.size()<<endl;
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }

  return 0;
}