#include <iostream>

class Node {
public:
  int val_;
  Node *next = nullptr;

  Node(int val) { val_ = val; }
};

class LinkedList {

public:
  Node *head;
  Node *tail;

  LinkedList() {
    // initialize the list with a 'dummy' node which makes removing
    // a node from the beginning of a list easier.
    head = new Node(-1);
    tail = head;
  }

  void insertEnd(int val) {
    tail->next = new Node(val);
    tail = tail->next;
  }

  void remove(int index) {
    int i = 0;

    Node *current = head;

    while (i < index && current) {
      i++;
      current = current->next;
    }

    if (current && current->next) {
      if (current->next == tail) {
        tail = current;
      }

      current->next = current->next->next;
    }
  }

  void print() {
    Node *current = head->next;

    while (current) {
      std::cout << current->val_ << " -> ";
      current = current->next;
    }

    std::cout << std::endl;
  }
};
