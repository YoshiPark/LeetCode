#include <iostream>
#include "Solution.h"
int main() {
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(3);
	ListNode* p3 = new ListNode(5);
	ListNode* q1 = new ListNode(2);
	ListNode* r1 = new ListNode(10);
	p1->next = p2;
	p2->next = p3;
	q1->next = p2;
	Solution example;
	ListNode* head = example.getIntersectionNode(p1, r1);
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}