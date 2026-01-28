#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  node* prev;
  node* next; 
  node(int val){
    this->data=val;
    this->prev=NULL;
    this->next=NULL;
  }
};

int getlen(node* head){
  int len = 0;
  while(head != nullptr){
    len++;
    head = head->next;
  }
  return len;
}

void print(node* head){
  cout<<"NULL-> ";
  while(head != nullptr){
    cout<<head->data<<"<->";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}

void insertAtfirst(node* &head,int val){
  node* n = new node(val);
  n->next = head;
  if(head != nullptr) head->prev = n;
  head = n;
}

void insertAtEnd(node* &head, int val){
  node* n = new node(val);
  if (head == NULL){
    insertAtfirst(head, val);
    return ;
  }
  node* temp = head;
  while (temp->next != NULL)  temp = temp->next;
  temp->next = n;
}

void insertAtIndex(node* &head, int val,int index){
  if(index==1){
    insertAtfirst(head,val);
    cout<<val<<" inserted at index "<<index<<endl;
    return;
  }
  node* temp=head;
  int count=1;
  if(temp == nullptr)  return;
  while (temp != nullptr && count < index-1){
    temp = temp->next;
    count++;
  }
  node* n=new node(val);
  n->next = temp->next;
  temp->next->prev=n;
  temp->next=n;
  n->prev=temp;
  cout<<val<<" inserted at index "<<index<<endl;
}

void del(node* &head, int index) {
  if (head == nullptr || index < 1)  return;
  if (index == 1) {
    node* todelete = head;
    head = head->next;
    if (head != nullptr)  head->prev = nullptr;
    delete todelete;
    return;
  }

  int count = 1;
  node* temp = head; 
  // Check if the node to delete is found or index out of bounds
  if (temp == nullptr)   return;
  while (temp != nullptr && count < index) {
    temp = temp->next;
    count++;
  }

  // Node is found, adjust the pointers
  if (temp->prev != nullptr)   temp->prev->next = temp->next;
  if (temp->next != nullptr)   temp->next->prev = temp->prev;
  else  temp->prev->next = nullptr;    // Set the next pointer of the previous node to nullptr
  //  Add this condition to handle the last node
  delete temp;
}

int main(){
  node* head = NULL;
  insertAtfirst(head,100);
  insertAtEnd(head,10);  
  insertAtEnd(head,20); 
  insertAtEnd(head,30);
  insertAtEnd(head,40);
  insertAtIndex(head,3000,4);
  cout<<"LinkList Before: ";
  print(head);
  cout<<"LinkList Length: "<<getlen(head)<<endl;

  del(head,4);
  cout<<"LinkList After: ";
  print(head);
  cout<<"LinkList Length: "<<getlen(head)<<endl;
  return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  node* prev;
  node* next; 
  node(int val){
    this->data=val;
    this->prev=NULL;
    this->next=NULL;
  }
};

void print(node* head){
   cout<<"NULL <-> ";
  while(head != nullptr){
    cout<<head->data<<" <-> ";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}

int getlen(node* head){
  int len = 0;
  while(head != nullptr){
    len++;
    head = head->next;
  }
  return len;
}

void inserthead(node* &head,node* &tail,int val){
    node* n=new node(val);
     if(head==nullptr){
        head=n;
        tail=n;
    }
    else{
        n->next=head;
        head->prev=n;
        head=n;
    }
}

void inserttail(node* &head,node* &tail,int val){
    node* n=new node(val);
    if(tail==nullptr){
        tail=n;
        head=n;
    }
    else{
        tail->next=n;
        n->prev=tail;
        tail=n;   
    }
}

void deletion(node *&head, int val){
  if (head == NULL)  return;

  if (head->data == val){
    node *todelete = head;
    head = head->next;
    if(head!=NULL) head->prev=NULL;
    delete todelete;
    return;
  }

  node *temp = head;
  while (temp->next != NULL && temp->next->data != val)  temp = temp->next;
  // If we found the node with the value to be deleted
  if (temp->next != NULL){
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
  }
}

void del(node* &head, int index) {
  // if the head is null or the index is invalid
  if (head == nullptr || index < 1)  return;
  
  // Delete the head node
  if (index == 1) {
    node* todelete = head;
    head = head->next;
    if (head != nullptr)  head->prev = nullptr;
    delete todelete;
    return;
  }

  int count = 1;
  node* temp = head;
  while (temp != nullptr && count < index) {
    temp = temp->next;
    count++;
  }

  // Check if the node to delete is found or index out of bounds
  if (temp == nullptr)   return;
    
  // Node is found, adjust the pointers
  if (temp->prev != nullptr)   temp->prev->next = temp->next;
  if (temp->next != nullptr)   temp->next->prev = temp->prev;
  else { // <--- Add this condition to handle the last node
    temp->prev->next = nullptr; // Set the next pointer of the previous node to nullptr
  }

  delete temp;
}

int main(){
    node* head=NULL; node* tail=NULL;
    inserthead(head,tail,11);
    inserttail(head,tail,12);    
    inserttail(head,tail,13);    
    inserttail(head,tail,14);    
    inserttail(head,tail,15);
    print(head);
    cout<<"LinkList Length: "<<getlen(head)<<endl;

    del(head,2);
    print(head);
    cout<<"LinkList Length: "<<getlen(head)<<endl;

   
    return 0;
}
*/
