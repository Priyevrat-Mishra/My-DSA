#include <bits/stdc++.h>
using namespace std;

class node{
public:
  int data;
  node *left;
  node *right;
  node(int val){
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

// Pre-Order =  node   left-call   right-call
void preOrder(node *root){
  if (root == NULL)  return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// In-Order = left-call   node     right-call
void inOrder(node *root){
  if (root == NULL)  return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

// Post-Order= left-call   right-call    node
void postOrder(node *root){
  if (root == NULL)  return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int main(){
  node *a = new node(1);
  node *b = new node(2);
  node *c = new node(3);
  node *d = new node(4);
  node *e = new node(5);
  node *f = new node(6);
  node *g = new node(7);
  a->left = b, a->right = c;
  b->left = d, b->right = e;
  c->left = f, c->right = g;
  preOrder(a);

  return 0;
}