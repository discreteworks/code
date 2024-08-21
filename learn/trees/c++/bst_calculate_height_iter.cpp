/* Binary Search Tree */
#include <iostream>
#include <stack>
#include <set>

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

int calculate_height_iter_depth_first(node *root) {
  if (root == nullptr) return 0;
  std::stack<node*> *stack = new std::stack<node*>();
  std::set<node*> visited;
  int height = 0;
  stack->push(root);

  while (!stack->empty()) {
    node* cur = stack->top();
    if (cur->left != nullptr && visited.end() == visited.find(cur->left)) {
      stack->push(cur->left);
    }
    else if (cur->right != nullptr && visited.end() == visited.find(cur->right)) {
      stack->push(cur->right);
    }
    else {
      visited.insert(cur);
      height = height > stack->size() ? height : stack->size();
      stack->pop();
    }
  }
  return height;
}

int main() {
  node *root = nullptr;
  root = add(root, 1);
  root = add(root, 3);
  root = add(root, 2);
  root = add(root, 5);
  root = add(root, 0);
  root = add(root, 4);
  root = add(root, 7);
  root = add(root, 8);
  std::cout << "Tree height:" << calculate_height_iter_depth_first(root) << std::endl;
}
