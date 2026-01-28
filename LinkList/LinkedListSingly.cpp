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

// search in linklist
bool search(node *head, int key){
  while (head != NULL){
    if (head->data == key)  return true;
    else head = head->next;
  }
  return false;
}

// traversal
void print(node* head){
  while (head != NULL){
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

// insert At first
void insertAtFirst(node* &head, int val){
  node *n = new node(val);
  n->next = head;
  head = n;
}

// insert At End
void insertAtEnd(node* &head, int val){
  node *n = new node(val);
  if (head == NULL){
    // head = n;
    insertAtFirst(head, val);
    return;
  }
  node *temp = head;
  while (temp->next != NULL)  temp = temp->next;
  temp->next = n;
}

// insert at index
void insertatindex(node *&head, int val, int index){
  node *n = new node(val);
  if (index == 1){
    insertAtFirst(head,val);
    cout<<val<<" inserted at index "<<index<<endl;
    return;
  }
  node *temp = head;
  int count = 0;
  if (temp == nullptr)  return;
  while (temp != nullptr && count < index - 1){
    temp = temp->next;
    count++;
  }
  // Insert the new node at the desired index
  n->next = temp->next;
  temp->next = n;
  cout<<val<<" inserted at index "<<index<<endl;
}

// deletion in linklist from head to n
void deletion(node *&head, int val){
  if (head == NULL)  return;

  // If the head's data is equal to the value to be deleted, update the head
  if (head->data == val){
    node *todelete = head;
    head = head->next;
    delete todelete;
    return;
  }

  // Initialize a temporary node to print the list until we find the node with the value to be deleted
  node *temp = head;
  while (temp->next != NULL && temp->next->data != val)  temp = temp->next;

  // If we found the node with the value to be deleted
  if (temp->next != NULL){
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
  }
}

int main(){
  node *head = nullptr;
  cout<<"Before deletion:"<<endl;
  insertAtEnd(head, 11);
  insertAtEnd(head,12);
  insertAtEnd(head,13);
  insertAtEnd(head,14);
  insertAtEnd(head,15);
  insertAtFirst(head, 10);
  insertatindex(head,22,3);
  print(head);

  // cout<<"Searching:"<<search(head,12)<<endl;

  deletion(head, 10);
  cout<<"After deletion:"<<endl;
  print(head);

  return 0;
}