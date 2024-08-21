#include <iostream>


struct node {
  int data;
  node *next;
  node(int data, node *next): data(data), next(next) {}
};

node* push(node *head, int data) {
  return new node(data, head);
}

node* pop(node *head, int *data) {
  if(head == nullptr) {
    return head;
  }
  node* n_head = head->next; // point to new head
  *data = head->data;
  delete head;
  return n_head;
}

int main() {
  int value = 0;
  node *head = nullptr;
  head = push(head, 1);
  head = push(head, 2);
  head = push(head, 3);
  head = pop(head, &value);
  std::cout << "pop:" << value << std::endl;
  head = pop(head, &value);
  std::cout << "pop:" << value << std::endl;
  return 0;
}
