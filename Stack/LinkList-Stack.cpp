#include <bits/stdc++.h>
using namespace std;

class node{  //user-defined data type
public:
  int data;
  node* next;
  node(int val){
    data=val;
    next=nullptr;
  }
};

class Stack{    //user-defined data structure
public:
  node* head;
  int size;
  Stack(){
    head=nullptr;
    size=0;
  }
  void push(int val){
    node* temp=new node(val);
    temp->next=head;
    head=temp;
    size++;
  }

  void pop(){
    if(head==nullptr){
      cout<<"stack is empty"<<endl;
      return;
    }head=head->next;
    size--;
  }

  int top(){
    if(head==nullptr){
      cout<<"stack is empty"<<endl;
      return -1;
    }
   return head->data;
  }

  void show(){
    node* temp=head;
    while(temp!=nullptr){
      cout<<temp->data<<endl;
      temp=temp->next;
    }
    cout<<endl;
  }
};

int main(){
  Stack st;
  cout<<st.top();
  st.push(10);
  st.push(20); 
  st.push(30);
  st.push(40);
  st.push(50);st.push(60);
  cout<<st.top()<<endl;;
  st.show();

  return 0;
}