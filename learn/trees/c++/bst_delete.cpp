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

void del(node *root) {
  //TODO
}

int main() {
  node *root = nullptr;
  root = add(root, 1);
  root = add(root, 3);
  root = add(root, 2);
  root = add(root, 4);
  root = add(root, 0);
  root = add(root, 5);
  int n;
  std::cout << "Enter node:";
  std::cin >> n;
  std::cout << "Deleted node:" << del(root) << std::endl;
}
