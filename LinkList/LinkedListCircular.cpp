#include <bits/stdc++.h>
using namespace std;

class node{
public:
  int data;
  node *next;
  node(int val){
    this->data = val;
    this->next = NULL;
  }
};

void print(node* head){
  node* temp = head;
  do{
    cout<<temp->data<<"->";
    temp = temp->next;
  }while(temp != head);
  cout<<endl;
  // cout<<head->data<<endl;
}

void insertFirst(node* &head,int val){  
  node* n = new node(val);
  if(head == NULL){
    n->next = n;
    head = n;
    return;
  }
  node* temp = head;
  while(temp->next != head) temp = temp->next;
  temp->next = n;
  n->next = head;
  head = n;
}

void insertEnd(node* &head,int val){
  if(head == NULL){
    insertFirst(head,val);
    return;
  }
  node* n = new node(val);
  node* temp = head;
  while(temp->next != head) temp = temp->next;
  temp->next = n;
  n->next = head;
}

void delHead(node* &head){
    node* temp = head;
    while(temp->next != head) temp = temp->next;
    node* todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

void del(node* &head,int index){
  if(head == NULL)  return;
  if(index == 1){
    delHead(head);
    return;
  }
  node* temp=head;
  // int cnt=1;
  // while(cnt<index-1){
  //   temp=temp->next;
  //   cnt++;
  // }
  for(int i=1; i<index-1; i++) temp = temp->next;
  node* todelete = temp->next;
  temp->next = temp->next->next;
  delete todelete;
}

int main(){
  node* head=nullptr;
  insertEnd(head,12);
  insertFirst(head,11);
  insertEnd(head,13);
  print(head);
 
  del(head,1);
  print(head);

  return 0;
}