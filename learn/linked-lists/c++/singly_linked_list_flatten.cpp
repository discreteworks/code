#include <iostream>

struct node {
  node *next;
  node *child;
  int data;
  node(node *next, node* child, int data): next(next), child(child), data(data) {}
};

node* add(node *head, node **tail,  node* child, int data) {
  if (head == nullptr) {
    node *n = new node(nullptr, child, data);
    *tail = n;
    return n;
  }
  return new node(head, child, data);
}

void add_child(node* p, node* child_head) {
  if (p != nullptr)
    p->child = child_head;
}

node* search(node *head, int data) {
  while (head !=nullptr) {
    if (data == head->data) {
      return head;
    }
    if (head->child != nullptr) {return search(head->child, data);}
    head = head->next;
  }
  return nullptr;
}

void traverse(node *head) {
  while (head !=nullptr) {
    std::cout <<  head->data <<  "\t";
    if (head->child != nullptr) {traverse(head->child);}
    head = head->next;
  }
}

void traverse_flat(node *head) {
  while (head !=nullptr) {
    std::cout <<  head->data <<  "\t";
    head = head->next;
  }
}

node *flat(node *head, node* tail) {
  if (head == nullptr) {
    return nullptr;
  }
  while (head !=nullptr) {
    if (head->child != nullptr) {
      tail->next = head->child;
      node *child_head = head->child;
      while (child_head->next != nullptr) {
          child_head = child_head->next;
      }
      tail = child_head;
    }
    head = head->next;
  }
  return tail;
}

bool search_child(node *head, node *n) {
  while (head !=nullptr) {
   if (n == head->child) { return true;}
   if (head->child != nullptr) {return search_child(head->child, n);}
    head = head->next;
  }
  return false;
}

node *un_flat(node *head, node *tail) {
  // find the first child and search it in the flat list and unlink.
   node *child = nullptr;
   node *curr = head;

   while (head !=nullptr) {
    node *tmp = curr;
    if (head->child != nullptr) {
      child = head->child;
    }
    if (head->next == child) {
      // reach the tail
      head->next = nullptr; // disconnect the flat
      tail = head; // update the tail
      // now disconnect the inner children
      child = child->next;
      while(1) {
        if (search_child(tmp, child->next)) {
           child->next = nullptr; // remove inner pointer.
           break;
        }
        child = child->next;
      }
      break;
    }
    head = head->next;
   }
   return tail;
}

int main() {
  node *head = nullptr;
  node *tail = nullptr;
  head = add(head, &tail, nullptr, 9);
  head = add(head, &tail, nullptr, 8);
  head = add(head, &tail, nullptr, 1);
  traverse(head);
  std::cout << std::endl;
  node *child_1_head = nullptr;
  node *child_1_tail = nullptr;
  child_1_head = add(child_1_head, &child_1_tail, nullptr, 4);
  child_1_head = add(child_1_head, &child_1_tail, nullptr, 3);
  child_1_head = add(child_1_head, &child_1_tail, nullptr, 2);
  add_child (head, child_1_head);
  traverse(head);
  node *child_2_head = nullptr;
  node *child_2_tail = nullptr;
  child_2_head = add(child_2_head, &child_2_tail, nullptr, 7);
  child_2_head = add(child_2_head, &child_2_tail, nullptr, 6);
  child_2_head = add(child_2_head, &child_2_tail, nullptr, 5);

  std::cout << std::endl;
  node* found = search(head, 4);
  if (found) {
    add_child(found, child_2_head);
  }
  traverse(head);
  std::cout << std::endl;
  tail = flat(head, tail);
  traverse_flat(head);
  std::cout << std::endl;
  tail  = un_flat(head, tail);
  traverse(head);
  std::cout << std::endl;
  return 0;
}
