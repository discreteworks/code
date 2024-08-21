#include <iostream>

struct  node {
  int data;
  node *next;
  node (int data, node *next): data(data), next(next) {}
};

node* add_node(node* head, int data) {

  if (head == nullptr) {
    node *temp = new node(data, head);
    temp->next = temp;
    return temp;
  } else {
      node *temp = new node(data, head);
      node *end = head;
      // no tail pointer so need to traverse till end to join the link
      while (head->next != end) {
        head = head->next;
      }
      head->next = temp;
      return temp;
  }
}

void traverse(node *head) {
  node *temp = head;
  if (head == nullptr) {
    return;
  }
  if (head->next == head) {
    std::cout << head->data << std::endl;
    return;
  }
  do {
    std::cout << head->data << std::endl;
    head = head->next;
  } while (head != temp);
}


node* search(node *head, int data) {
  node *temp = head;
  if (head->next == head && head->data ==  data) {
   return head;
  }
  do {
    if (head->data == data) {
      return head;
    }
    head = head->next;
  } while (head != temp);
  return nullptr;
}

node* delete_node(node *head, node* to_delete) {
  node *temp = head;
  if (!to_delete) {
    return head;
  }
  if (head->next == head && head == to_delete) {
    delete head;
    return nullptr;
  }
  do {
    if (head->next == to_delete) {
      //std::cout << "head->data:" << head->data << std::endl;
      head->next = to_delete->next;
      if (to_delete == temp) { // first and last node
         delete to_delete;
         return head->next;
      } else { // middle node
         delete to_delete;
         return temp;
      }
    }
    head = head->next;
  } while (head != temp);
  return temp;
}

int main() {
  node *head = nullptr;
  head = add_node(head, 1);
  head = add_node(head, 2);
  head = add_node(head, 3);
  head = add_node(head, 4);
  traverse(head);
  std::cout << "delete:" << 1  << std::endl;
  node *n1 = search(head, 1);
  head = delete_node(head, n1);
  traverse(head);
  std::cout << "delete:" << 2  << std::endl;
  node *n2 = search(head, 2);
  head = delete_node(head, n2);
  traverse(head);
  std::cout << "delete:" << 3  << std::endl;
  node *n3 = search(head, 3);
  head = delete_node(head, n3);
  traverse(head);
  std::cout << "delete:" << 4  << std::endl;
  node *n4 = search(head, 4);
  head = delete_node(head, n4);
  traverse(head);
  return 0;
}
