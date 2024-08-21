#include <iostream>

template<typename T>
class link_list {
public:
link_list (): head(nullptr) {}
public:
  struct  node {
    node *next;
    T data;
    node(node *next, T data):next(next), data(data) {}
  };
private:
  node* head;
public:
  void add(T data) {
    if (head == nullptr) {
      head = new node(nullptr, data);
    } else  {
      head = new node(head, data);
    }
  }
  void traverse() {
    if (head == nullptr) {
      return;
    }
    node *curr = head;
    while (curr != nullptr) {

      std::cout << curr->data << std::endl;
      curr = curr->next;
    }
  }
  node *search(T data) {
    if (head == nullptr) {
      return nullptr;
    }
    node *curr = head;
    while (curr != nullptr) {
      if (curr->data == data) {
        return curr;
      }
      curr = curr->next;
    }
    return nullptr;
  }
  void insert_after(node *after, T data) {
    if (head == nullptr) {
      return;
    }
    node *curr = head;
    while (curr != nullptr) {
      if (curr ==  after) {
        curr->next = new node(curr->next, data);
        return;
      }
      curr = curr->next;
    }
  }
  void reverse() {
    node *prev = nullptr;
    node *curr = head;
    while (curr !=  nullptr) {
      if (curr->next == nullptr) // set the last node to be new head
        head = curr;
      node *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next; // advance the pointer
    }
  }
  node* get_kth_node_from_end(int k) {
      int i = 0;
      node *adv = head;
      node *curr = head;
      while (adv != nullptr && i <= k) {
        adv = adv->next;
        i++;
      }
      if (i <= k) {return nullptr;}
      while (adv != nullptr) {
        curr = curr->next;
        adv = adv->next;
      }
      if (curr) {
          return curr;
      }
      return nullptr;
  }
  node *get_mid_node() {
    node *curr = head;
    node *adv = curr->next;
    while (adv != nullptr) {
      adv = adv->next;
      curr = curr->next;
      if (adv != nullptr) {
        adv = adv->next;
      }
    }
    return curr;
  }
};

int main() {
  link_list<int> ll;
  ll.add(2);
  ll.add(3);
  ll.traverse();
  std::cout << std::endl;
  ll.reverse();
  ll.traverse();
  std::cout << std::endl;
  ll.add(1);
  ll.traverse();
  std::cout << std::endl;
  ll.insert_after(ll.search (3), 4);
  ll.traverse();
  std::cout << std::endl;
  ll.insert_after(ll.search (4), 5);
  ll.traverse();
  link_list<int>::node *node_k = ll.get_kth_node_from_end(3);
  std::cout << "node_k->data:" <<node_k->data << std::endl;
  link_list<int>::node *node_m = ll.get_mid_node();
  std::cout << "node_m->data:" <<node_m->data << std::endl;
  return 0;
}
