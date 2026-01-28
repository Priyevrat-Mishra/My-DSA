#include <bits/stdc++.h>
using namespace std;

class node{
public:
  int data;
  node* left;
  node* right;
  node(int val){
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

void show(node* root){
  if(root == NULL)return;
  cout<<root->data<<" ";
  show(root->left);
  show(root->right);
}

int tsum(node* root){
  if(root == NULL)return 0;
  return root->data + tsum(root->left) + tsum(root->right);
}

int tsize(node* root){
  if(root == NULL)return 0;
  return 1 + tsize(root->left) + tsize(root->right);
}

int tmax(node* root){
  if(root == NULL)return INT_MIN;
  int lmax = tmax(root->left);
  int rmax = tmax(root->right);
  return  max(root->data,max(lmax,rmax));
}

int leaf(node* root){
  if(!root) return 0;
  if(!root->left && !root->right) return 1;
  return leaf(root->left)+leaf(root->right);
}

int nonLeaf(node* root){
  if(!root) return 0;
  if(!root->left && !root->right) return 0;
  return 1 + nonLeaf(root->left) + nonLeaf(root->right);
}

int height(node* root){
  if(!root)   return 0;
  return 1+max(height(root->left),height(root->right));
}

bool same(node* r1,node* r2){
  if(!r1 && !r2)     return true;
  if((!r1 && r2) || (r1 && !r2))  return false;
  if(r1->data != r2->data)  return false;
  return same(r1->left,r2->left) && same(r1->right,r2->right);
}

void mirror(node* root){
  if(!root) return;
  node* t = root->right;
  root->right = root->left;
  root->left = t;
  mirror(root->left);
  mirror(root->right);
}

int main(){
  node* a = new node(1);
  node* b = new node(2);  
  node* c = new node(3);  
  node* d = new node(4);  
  node* e = new node(5);
  node* f = new node(6);
  node* g = new node(7);
  a->left = b, a->right = c;
  b->left = d, b->right = e;
  c->left = f, c->right = g;
  show(a);
  cout<<"\nSum: "<<tsum(a)<<endl;
  cout<<"Size: "<<tsize(a)<<endl;
  cout<<"MaxValue: "<<tmax(a)<<endl;
  cout<<"Tree Height: "<<height(a);
  cout<<"\nLeaf Nodes : "<<leaf(a);
  cout<<"\nNon-Leaf Nodes: "<<nonLeaf(a);
  cout<<"\nIdentical Tree: "<<same(a,a);
  cout<<"\nMirror Tree : ";
  mirror(a);
  show(a);

  return 0;
}