#include <bits/stdc++.h>
using namespace std;

//travsersal recursive
void show(stack<int>&s){
  if(s.size() == 0) return;
  int x = s.top();
  // cout<<x<<" ";     
  s.pop();
  show(s);
  cout<<x<<" ";   
  s.push(x);
}

//recursion insertion
void pushdown(stack<int>&s,int val){
  if(s.size() == 0){
    s.push(val);
    return;
  }
  int x = s.top();
  s.pop();
  pushdown(s,val);
  s.push(x);
}

//reverse insertion in same stack recursively
void reverse(stack<int>&s){
  if(s.size() == 0)  return;
  int x = s.top();
  s.pop();
  reverse(s);
  pushdown(s,x);
}

int main(){
  stack<int>s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  show(s);
  cout<<endl;
  // pushdown(s,100);
  reverse(s);
  show(s);

  return 0;
}