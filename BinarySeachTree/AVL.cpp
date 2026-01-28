#include<iostream>
using namespace std;

class node{
public:
  int data, height;
  node *left, *right;
  node(int val){
    data = val;
    height = 1;
    left = right = NULL;
  }
};

void show(node* root){
  if(!root) return;
  show(root->left);
  cout<<root->data<<" ";
  show(root->right);
}

int getHeight(node* root){
  if(!root)  return 0;
  return root->height;
}

int getBalance(node* root){
  return getHeight(root->left) - getHeight(root->right);
}

node* leftRotation(node* root){
  node* child = root->right;
  node* childLeft = child->left;

  child->left = root;
  root->right = childLeft;

  root->height = 1+max(getHeight(root->left), getHeight(root->right));
  child->height = 1+max(getHeight(child->left), getHeight(child->right));
  return child;
}

node* rightRotation(node* root){
  node* child = root->left;
  node* childRight = child->right;

  child->right = root;
  root->left = childRight;

  root->height = 1+max(getHeight(root->left), getHeight(root->right));
  child->height = 1+max(getHeight(child->left), getHeight(child->right));
  return child;
}

node* insert(node* root, int key){
  if(!root) return new node(key);
  if(root->data > key)
    root->left = insert(root->left, key);
  else if(root->data < key)
    root->right = insert(root->right, key);
  else return root;

  // Height Update
  root->height = 1+ max(getHeight(root->left),getHeight(root->right));

  // Balancing Check
  int balance = getBalance(root);

  // Left Left
  if(balance > 1 && root->left->data > key)
    return rightRotation(root);
  
  // Right Right
  else if(balance < -1 && root->right->data < key)
    return leftRotation(root);

  // Left Right
  else if(balance > 1 && root->left->data < key){
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }

  // Right Left
  else if(balance < -1 && root->right->data > key){
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }

  // No Unbalance
  else return root;
}

node* deleteNode(node *root, int key){
  if (!root)  return NULL;  

  if (root->data > key)
    root->left = deleteNode(root->left, key);
  else if (root->data < key)
    root->right = deleteNode(root->right, key);
  else{
    // Deleting Leaf node
    if (!root->left && !root->right){
      delete root;
      return NULL;
    }
    // Deleting Left node
    else if (root->left && !root->right){
      node *temp = root->left;
      delete root;
      return temp;
    }
    // Deleting Right node
    else if (!root->left && root->right){
      node *temp = root->right;
      delete root;
      return temp;
    }
    else{
      node *curr = root->right;
      while (curr->left)
        curr = curr->left;
      root->data = curr->data;
      root->right = deleteNode(root->right, curr->data);
    }
  }
  // Updating Height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  int bal = getBalance(root);
  // Left Side
  if (bal > 1){
    // Left Left
    if (getBalance(root->left) >= 0)
      return rightRotation(root);
    // Left Right
    else{
      root->left = leftRotation(root->left);
      return rightRotation(root);
    }
  }
  // Right Side
  else if (bal < -1){
    // Right Right
    if (getBalance(root->right) <= 0)
      return leftRotation(root);
    // Right Left
    else{
      root->right = rightRotation(root->right);
      return leftRotation(root);
    }
  }
  else  return root;
}

int main(){
  node* root = nullptr;
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 15);
  root = insert(root, 60);
  root = insert(root, 65);
  root = insert(root, 5);
  show(root);

  return 0;
}