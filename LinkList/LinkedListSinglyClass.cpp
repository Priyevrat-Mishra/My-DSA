#include <bits/stdc++.h>
using namespace std;

class node{
public:
  int data;
  node* next;
  node(int val){
    this->data = val;
    this->next = NULL;
  }
};

class LinkedList{
public:
  node* head;
  node* tail;
  int size;
  LinkedList(){
    head = tail = NULL;
    size = 0;
  }

  void show(){
    node* temp = head;
    while (temp != NULL){
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  void insertAtFirst(int val){
    node* temp = new node(val);
    temp->next = head;
    head = temp;
    size++;
  }

  void insertAtEnd(int val){
    node *temp = new node(val);
    if(size == 0)head = tail = temp;
    else{
      tail->next = temp;
      tail = temp;
    }
    size++;
  }

  void insertAtIdx(int idx, int val){
    if(idx == 0){
      insertAtFirst(val);
      return;
    }
    else if(idx >= size){
      insertAtEnd(val);
      return;
    }
    else{
      node* n = new node(val);
      node* temp = head;
      for(int i=1;i<idx;i++)  temp = temp->next;
      n->next = temp->next;
      temp->next = n;
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
    size--;
  }

  void deleteTail(){
    if(size==0){
      cout<<"List is Empty!\n";
      return;
    }
    node* temp = head;
    while(temp->next != tail) temp = temp->next;
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
      for(int i=1;i<idx-1;i++)temp = temp->next;
      temp->next = temp->next->next;
      size--;
    }
  }
  
};

int main(){
  LinkedList ll;
  ll.insertAtEnd(10);
  ll.insertAtEnd(20);
  ll.insertAtEnd(30);
  ll.insertAtFirst(100);
  ll.insertAtIdx(8,2000);
  ll.insertAtIdx(8,3000);
  ll.insertAtIdx(8,4000);
  ll.show();
  // ll.deleteHead();
  // ll.deleteTail();
  ll.deleteAtIdx(1);
  ll.show();
  cout<<ll.size<<endl;
  cout<<ll.getAtIdx(9);


  return 0;
}