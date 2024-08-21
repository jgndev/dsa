#include <iostream>

using std::cout;
using std::endl;

class Node {
public:
  int val;
  Node *next = nullptr;
  Node *prev = nullptr;

  Node() = default;
  Node(int val = 0, Node *next = nullptr, Node *prev = nullptr)
      : val(val), next(next), prev(prev){};
};

class LinkedList {
public:
  Node *head;
  Node *tail;

  LinkedList() {
    head = new Node(-1);
    tail = new Node(-1);
    head->next = tail;
    tail->prev = head;
  }

  void insert_end(int val) {
    Node *newNode = new Node(val);
    newNode->prev = head;
    newNode->next = head->next;

    head->next->prev = newNode;
    head->next = newNode;
  }

  void removeFront() {
    head->next->next->prev = head;
    head->next = head->next->next;
  }

  void removeEnd() {
    tail->prev->prev->next = tail;
    tail->prev = tail->prev->prev;
  }

  void print() {
    Node *curr = head->next;

    while (curr != tail) {
      cout << curr->val << " -> ";
      curr = curr->next;
    }

    cout << endl;
  }
};
