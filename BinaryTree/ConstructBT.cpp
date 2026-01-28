#include <bits/stdc++.h>
using namespace std;
#define m INT_MIN

class node{
public:
  int data;
  node *left,*right;
  node(int val){
    data = val;
    left = right = NULL;
  }
};

void show(node* root){     //DFS
  if(!root)  return;
  cout<<root->data<<" ";
  show(root->left);
  show(root->right);
}

node* construct(int arr[], int n){
  node* root = new node(arr[0]);
  queue<node*> q;
  q.push(root);
  int i = 1, j = 2;
  while (!q.empty() && i < n){
    node *temp = q.front();
    q.pop();

    node *l, *r;
    l = arr[i] != m ? new node(arr[i]) : NULL;
    r = j != n && arr[j] != m ? new node(arr[j]) : NULL;
    temp->left = l, temp->right = r;

    if (l)  q.push(l);
    if (r)  q.push(r);
    i += 2, j += 2;
  }
  return root;
}

node* BT(){
  int x;
  cin>>x;
  if(x == -1) return NULL;
  node* t = new node(x);
  t->left = BT();
  t->right = BT();
  return t;
}

int main(){
  //Method 1--------
  node* root = BT();
  show(root);

  //Method 2--------
  int arr[] = {1, 2, 3, 4, 5, m, 6, m, m, 7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  node* root = construct(arr, n);
  show(root);

  //Method 3--------
  int a, b, x = 10;
  queue<node*>q;
  node* root = new node(x);
  q.push(root);

  while(!q.empty()){
    node* t = q.front();
    q.pop();

    cout<<"Enter Left Child of "<<t->data<<" : ";
    cin>>a;
    if(a > -1)  q.push(new node(a));
  
    cout<<"Enter Right Child of "<<t->data<<" : ";
    cin>>b;
    if(b > -1)  q.push(new node(b));
  }
  return 0;
}