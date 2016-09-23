#include <iostream>
#include "Solution.hpp"
int main() {
  ListNode* l1 = new ListNode(2);
  ListNode* l2 = new ListNode(4);
  ListNode* l3 = new ListNode(3);
  l1->next = l2;
  l2->next = l3;
  ListNode* q1 = new ListNode(5);
  ListNode* q2 = new ListNode(6);
  ListNode* q3 = new ListNode(4);
  q1->next = q2;
  q2->next = q3;
  Solution example;
  ListNode* head = example.addTwoNumbers(l1, q1);
  ListNode* p = head;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
  return 0;
}
