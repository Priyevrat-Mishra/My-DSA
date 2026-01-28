#include <bits/stdc++.h>
using namespace std;

class Queue{
public:
  int f;
  int b;
  int s;
  vector<int>arr;
  Queue(int val){
    f = 0;
    b = 0;
    s = 0;
    vector<int>v(val);
    arr = v;
  }
  void push(int val){
    if(b == arr.size()){
      cout<<"Queue is Full"<<endl;
      return;
    }
    arr[b++]=val;
    s++;
  }
  void pop(){
    if(s == 0){
      cout<<"Queue is Empty"<<endl;
      return;
    }
    f++,s--;
  }
  int front(){
    if(s == 0){
      cout<<"Queue is Empty"<<endl;
      return -1;
    }
    return arr[f];
  }
  int back(){
    if(s == 0){
      cout<<"Queue is Empty"<<endl;
      return -1;
    }
    return arr[b-1];
  }
  int size(){
    return s;
  }
  bool empty(){
    return s == 0;
  }
  void show(){
    for(int i=f;i<b;i++)cout<<arr[i]<<" ";
    cout<<endl;
  }
};

int main(){
  Queue q(6);
  q.push(1);
  q.push(2); 
  q.push(3); 
  q.push(4);
  q.push(5);
  q.push(6);
  q.show();
  q.pop();
  q.show();
  cout<<q.front();

  return 0;
}