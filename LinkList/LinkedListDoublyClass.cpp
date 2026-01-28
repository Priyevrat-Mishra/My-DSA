#include <bits/stdc++.h>
using namespace std;

class node{
public:
  int data;
  node* prev;
  node* next;
  node(int val){
    this->data = val;
    this->prev = NULL;
    this->next = NULL;
  }
};

class DLL{
public:
  node* head;
  node* tail;
  int size;
  DLL(){
    head = tail = NULL;
    size = 0;
  }

  void show(){
    cout << "NULL <- ";
    node* temp = head;
    while (temp){
      cout << temp->data << " <-> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  void insertAtHead(int val){
    node* temp = new node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
    size++;
  }

  void insertAtTail(int val){
    node* temp = new node(val);
    if(size == 0)head = tail = temp;
    else{
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
    size++;
  }

  void insertAtIdx(int idx, int val){
    if(idx == 0){
      insertAtHead(val);
      return;
    }
    else if(idx >= size){
      insertAtTail(val);
      return;
    }
    else{
      node* n = new node(val);
      node* temp = head;
      for(int i=1;i<idx;i++)  temp = temp->next;
      n->next = temp->next;
      temp->next = n;
      n->prev = temp;
      n->next->prev = n;
      size++;
    }
  }

  int getAtIdx(int idx){
    if(idx < 0 || idx>=size)  return -1;
    else if(idx == 0)  return head->data;
    else if(idx == size-1)  return tail->data;
    else{
      node* temp = head;
      for(int i=0;i<idx;i++)temp = temp->next;
      return temp->data;
    }
  }

  void deleteHead(){
    if(size==0){
      cout<<"List is Empty!\n";
      return;
    }
    head = head->next;
    if(head) head->prev = NULL;
    if(head==NULL)tail = NULL;
    size--;
  }

  void deleteTail(){
    if(size==0){
      cout<<"List is Empty!\n";
      return;
    }
    else if(size==1){
      deleteHead();
      return;
    }
    node* temp = tail->prev;
    temp->next = NULL;
    tail = temp;
    size--;
  }

  void deleteAtIdx(int idx){
    if(idx < 0 || idx>=size){
      cout<<"Invalid Index!\n";
      return;
    }
    else if(idx == 0){  
      deleteHead();
      return;
    }
    else if(idx == size-1){
      deleteTail();  
      return;
    }
    else{
      node* temp = head;
      for(int i=1;i<=idx-1;i++)temp = temp->next;
      temp->next = temp->next->next;
      temp->next->prev = temp;
      size--;
    }
  }
  
};

int main(){
  DLL ll;
  ll.insertAtTail(10);
  ll.insertAtTail(20);
  ll.insertAtTail(30);
  ll.insertAtHead(100);
  ll.insertAtIdx(3,2000);
  ll.insertAtIdx(8,3000);
  ll.insertAtIdx(8,4000);
  ll.show();
  // ll.deleteHead();
  // ll.deleteTail();
  ll.deleteAtIdx(5);
  ll.show();
  cout<<ll.size<<endl;
  // cout<<ll.getAtIdx(2);


  return 0;
}