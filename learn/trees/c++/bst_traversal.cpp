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

node *find(node* root, int data) {
  if (root == nullptr)
    return nullptr;
  while (root != nullptr) {
    if (root->data == data) {
      return root;
    }
    if (data > root->data) {
      root = root->right;
      continue;
    }
    if (data < root->data) {
      root = root->left;
    }
  }
  return nullptr;
}

node* find_recursive(node *root, int data) {
  if (root == nullptr) return nullptr;
  if (root->data == data) return root;
  if (data > root->data) {
    find_recursive(root->right, data);
  } else if (data < root->data) {
    find_recursive(root->left, data);
  }
  return root;
}

void inorder_traversal(node *root) {
  if (root == nullptr) return;
  inorder_traversal(root->left);
  std::cout << root->data << "\t";
  inorder_traversal(root->right);
}

void preorder_traversal(node *root) {
  if (root == nullptr) return;
  std::cout << root->data << "\t";
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

void postorder_traversal(node *root) {
  if (root == nullptr) return;
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  std::cout << root->data << "\t";
}

int main() {
  node *root = nullptr;
  root = add(root, 1);
  root = add(root, 3);
  root = add(root, 2);
  root = add(root, 4);
  root = add(root, 0);
  root = add(root, 5);
  std::cout << "In order traversal:" << std::endl;
  inorder_traversal(root);
  std::cout << std::endl;
  std::cout << "Pre order traversal:" << std::endl;
  preorder_traversal(root);
  std::cout << std::endl;
  std::cout << "Post order traversal:" << std::endl;
  postorder_traversal(root);
  std::cout << std::endl;
}
