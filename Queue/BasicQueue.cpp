#include <bits/stdc++.h>
using namespace std;

void show(queue<int>&q){
  int n=q.size();
  for(int i=0;i<n;i++){
    int x = q.front();
    cout<<x<<" ";
    q.pop();
    q.push(x);
  }
  cout<<endl;
} 

void reverse(queue<int>&q){
  stack<int>s;
  while(q.size()>0){
    s.push(q.front());
    q.pop();
  }
  while(s.size()>0){
    q.push(s.top());
    s.pop();
  }
}

int main(){
  queue<int>q;
  q.push(1);
  q.push(2);  
  q.push(3);  
  q.push(4);
  q.push(5);
  // q.pop();
  show(q);
  reverse(q);
  show(q);
  reverse(q);
  show(q);

  return 0;
}