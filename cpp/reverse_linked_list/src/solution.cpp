#include "solution.h"

Node *Solution::reverse_linked_list(Node *head) {
  Node *prev = nullptr;
  Node *curr = head;

  while (curr != nullptr) {
    Node *tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }

  return prev;
}
