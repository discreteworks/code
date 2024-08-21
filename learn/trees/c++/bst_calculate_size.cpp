/* Binary Search Tree */
#include <iostream>

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
  int left = calculate_height(root->left);
  int right = calculate_height(root->right);
  return (1 + left + right);
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
