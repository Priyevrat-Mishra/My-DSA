#include <bits/stdc++.h>
using namespace std;
#define m INT_MIN

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

node* construct(int arr[], int n){
  node* root = new node(arr[0]);
  queue<node*> q;
  q.push(root);
  int i = 1, j = 2;
  while (q.size() > 0 && i < n){
    node *temp = q.front();
    q.pop();

    node *l, *r;
    l = (arr[i] != m) ? new node(arr[i]) : NULL;
    r = (j != n && arr[j] != m) ? new node(arr[j]) : NULL;
    temp->left = l, temp->right = r;

    if (l)  q.push(l);
    if (r)  q.push(r);
    i += 2, j += 2;
  }
  return root;
}

void leftBoundary(node *root){
  if (root == NULL)  return;
  if (root->left == NULL && root->right == NULL)  return;
  cout << root->data << " ";
  leftBoundary(root->left);
  if (root->left == NULL)  leftBoundary(root->right);
}

void rightBoundary(node *root){
  if (root == NULL)  return;
  if (root->left == NULL && root->right == NULL)  return;
  rightBoundary(root->right);
  if (root->right == NULL)  rightBoundary(root->left);
  cout << root->data << " ";
}

void bottumBoundary(node *root){
  if (root == NULL)  return;
  if (root->left == NULL && root->right == NULL)
    cout << root->data << " ";
  bottumBoundary(root->left);
  bottumBoundary(root->right);
}

void boundary(node* root){
  leftBoundary(root);
  bottumBoundary(root);
  rightBoundary(root->right);
}

int main(){
  int arr[] = {1, 2, 3, 4, 5, m, 6, 7, m, 8, m, 9, 10, m, 11, m, 12, m, 13, m, 14, 15, 16, m, 17, m, m, 18, m, 19, m, m, m, 20, 21, 22, 23, m, 24, 25, 26, 27, m, m, 28, m};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  node* root = construct(arr, n);
  boundary(root);

  return 0;
}