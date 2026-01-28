#include <bits/stdc++.h>
using namespace std;

void show(queue<int>&q){
  int n = q.size();
  for(int i=0;i<n;i++){
    int x = q.front();
    cout<<x<<" ";
    q.pop();
    q.push(x);
  }
  cout<<endl;
} 

void removeAtEven(queue<int>&q){
  int n = q.size();
  for(int i = 0; i < n; i++){
    if(i%2 != 0)
      q.push(q.front());
    q.pop();
  }
}

int main(){
  queue<int>q;
  q.push(1);
  q.push(2);  
  q.push(3);  
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);
  q.push(8);
  show(q);
  removeAtEven(q);
  show(q);

  return 0;
}