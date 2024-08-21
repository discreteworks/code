/* Binary Search Tree traversal using Breath First */
#include <iostream>
#include <stack>
#include <set>

struct node {
  node *left;
  node *right;
  int data;
  node(node* left, node *right, int data): left(left), right(right), data(data) {}
};

node* add (node *root, int data) {
  if (root == nullptr) {
    return new node(nullptr, nullptr, data);
  }
  node *head = root;
  while (root != nullptr) {
    if (root->data > data) {
      if (root->left == nullptr) {
        root->left = new node(nullptr, nullptr, data);
        return head;
      }
      root = root->left;
      continue;
    } if (root->data < data) {
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

void preorder_traversal_breath_first(node *root) {
  if (root == nullptr) return;
  std::stack<node*> stk;
  stk.push(root);
  while (!stk.empty()) {
    node* top = stk.top();
    stk.pop();
    std::cout << top->data << "\t";
    if (top->left != nullptr) {
      stk.push(top->left);
    }
    if (top->right != nullptr) {
      stk.push(top->right);
    }
  }
}

void postorder_traversal_depth_first(node *root) {
  if (root == nullptr) return;
  std::stack<node*> stk;
  std::set<node*> visited;
  stk.push(root);
  while (!stk.empty()) {
    node* top = stk.top();
    if (top->left != nullptr && visited.end() == visited.find(top->left)) {
      stk.push(top->left);
    }
    else if (top->right != nullptr && visited.end() == visited.find(top->right)) {
      stk.push(top->right);
    }
    else {
      visited.insert(top);
      std::cout << top->data << "\t";
      stk.pop();
    }
  }
}

int main() {
  node *root = nullptr;
  root = add(root, 1);
  root = add(root, 3);
  root = add(root, 2);
  root = add(root, 4);
  root = add(root, 0);
  root = add(root, 5);
  std::cout << "Pre order traversal (breath first):" << std::endl;
  preorder_traversal_breath_first(root);
  std::cout << std::endl;
  std::cout << "Post order traversal (depth first) :" << std::endl;
  postorder_traversal_depth_first(root);
  std::cout << std::endl;
}
