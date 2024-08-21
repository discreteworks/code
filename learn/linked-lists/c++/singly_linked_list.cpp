#include <iostream>

struct node {
  int data;
  node *next;
  node (int data, node* next): data(data), next(next) {}
};

node* add_node(node *head, int data) {
  if (head == nullptr) {
    return new node(data, nullptr);
  }
  else {
    return new node(data, head);
  }
}

node *search(node *head, int data) {
  while (head != nullptr) {
    if (head->data == data) {
      return head;
    }
    head = head->next;
  }
  return nullptr;
}

void traverse(node *head) {
  while (head != nullptr) {
    std::cout << head->data << std::endl;
    head = head->next;
  }
}

node* delete_node(node *head, node *to_del) {
  if (!to_del) {
    return head;
  }
  if (head->next ==  nullptr) {
    delete(to_del);
    return nullptr;
  }
  while (head != nullptr) {
    if (head->next == to_del) {
      head->next = to_del->next;
      delete(to_del);
      return head;
    }
    head = head->next;
  }
  return head;
}

node* delete_list(node *head) {
  while ( head != nullptr) {
    node* temp = head->next;
    delete (head);
    head = temp;
  }
  return nullptr;
}

int main() {
  node *head = nullptr;
  head = add_node(head, 10);
  //std::cout << head;
  head = add_node(head, 12);
  head = add_node(head, 11);
  traverse(head);
  node * to_del = search(head, 12);
  delete_node(head, to_del);
  traverse(head);
  head = delete_list(head);
  traverse(head);
  return 0;
}
