/* Binary Search Tree */
#include <iostream>
#include <stack>

struct node {
  node *left;
  node *right;
  int data;
  node(node* left, node* right, int data): left(left), right(right), data(data) { }
};

node* add(node *root, int data) {
  if (root == nullptr) {
    return new node(nullptr, nullptr, data);
  }
  node *head = root;
  while (root != nullptr) {
    if (data < root->data) {
      if (root->left == nullptr) {
        root->left = new node(nullptr, nullptr, data);
        return head;
      }
      root = root->left;
      continue;
    }
    if (data > root->data) {
      if (root->right == nullptr) {
        root->right = new node(nullptr, nullptr, data);
        return head;
      }
      root = root->right;
      continue;
    }
  }
  return head;
}

int calculate_height(node *root) {
  if (root == nullptr) return 0;
  std::stack<node*> stk;
  int size = 0;
  stk.push(root);
  while (!stk.empty()) {
    node* top = stk.top();
    stk.pop();
    if (top->left != nullptr) {
      stk.push(top->left);
    }
    if (top->right != nullptr) {
      stk.push(top->right);
    }
    size++;
  }
  return size;
}

int main() {
  node *root = nullptr;
  root = add(root, 1);
  root = add(root, 3);
  root = add(root, 2);
  root = add(root, 4);
  root = add(root, 0);
  root = add(root, 5);
  std::cout << "Tree size:" << calculate_height(root) << std::endl;
}
