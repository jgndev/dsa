#pragma once

class Node {
public:
  int val;
  Node *next;

  Node(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  Node *reverse_linked_list(Node *head);
};
