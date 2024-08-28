#include "solution.h"
#include <gtest/gtest.h>
#include <vector>

// Helper function to create a linked list form a vector
Node *create_linked_list(const std::vector<int> &values) {
  Node dummy(0);
  Node *current = &dummy;

  for (int val : values) {
    current->next = new Node(val);
    current = current->next;
  }

  return dummy.next;
}

// Helper function to convert a linked list to a vector
std::vector<int> linked_list_to_vector(Node *head) {
  std::vector<int> result;

  while (head) {
    result.emplace_back(head->val);
    head = head->next;
  }

  return result;
}

class SolutionTest : public ::testing::Test {
protected:
  Solution solution;
};

TEST_F(SolutionTest, TestCaseOne) {
  Node *head = create_linked_list({1, 2, 3, 4, 5});
  Node *reversed = solution.reverse_linked_list(head);
  std::vector<int> result = linked_list_to_vector(reversed);
  std::vector<int> expected = {5, 4, 3, 2, 1};
  EXPECT_EQ(result, expected);
}

TEST_F(SolutionTest, TestCaseTwo) {
  Node *head = create_linked_list({1});
  Node *reversed = solution.reverse_linked_list(head);
  std::vector<int> result = linked_list_to_vector(reversed);
  std::vector<int> expected = {1};
  EXPECT_EQ(result, expected);
}

TEST_F(SolutionTest, TestCaseThree) {
  Node *head = nullptr;
  Node *reversed = solution.reverse_linked_list(head);
  std::vector<int> result = linked_list_to_vector(reversed);
  std::vector<int> expected = {};
  EXPECT_EQ(result, expected);
}
