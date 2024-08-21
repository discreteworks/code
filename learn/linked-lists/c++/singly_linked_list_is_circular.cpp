#include <iostream>

struct node {
  node *next;
  int data;
  node(node *next, int data): next(next), data(data) {}
};

node* add(node *head, int data) {
  if (head == nullptr) {
    return new node(nullptr, data);
  }
  return new node(head, data);
}

node* search(node *head, int data) {
  if (head == nullptr)
    return nullptr;

  while (head != nullptr) {
    if (head->data == data) {
      return head;
    }
    head = head->next;
  }
  return nullptr;
}

void traverse(node *head) {
  while (head!=nullptr) {
    std::cout << head->data << std::endl;
    head = head->next;
  }
}

void update_link(node *n, node *next) {
  if (n == nullptr)
    return;
  if (next != nullptr) {
    n->next = next;
  }
}

bool is_circular(node *head) {
  if (head == nullptr) {
    return false;
  }
  node* fast = head->next;
  while (head != nullptr) {
    if (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      if (fast != nullptr && (fast->next == head || fast == head)){
        return true;
      }
    }
    head = head->next;
  }
  return false;
}

int main() {
  std::cout << "circular check" << std::endl;
  node *head = nullptr;
  head = add(head, 1);
  head = add(head, 2);
  head = add(head, 3);
  head = add(head, 4);
  head = add(head, 5);
  traverse(head);
  node *last = search(head, 1);
  node *mid = search(head, 3);
  update_link(last, mid);
  std::cout << is_circular(head) << std::endl;
}
