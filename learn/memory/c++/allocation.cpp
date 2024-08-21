#include <iostream>

struct node {
  node *next;
  int data;
  node(node *next, int data):next(next), data(data) {}
};

int main() {
  node *n = new node(nullptr, 1);
  std::cout << "Node data:" << n->data << std::endl;
  delete n;
  return 0;
}
