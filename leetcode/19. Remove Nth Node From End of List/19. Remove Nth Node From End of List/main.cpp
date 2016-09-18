#include <iostream>
#include "Solution.h"
using namespace std;
int main() {
	ListNode* head = new ListNode(1);
	int num;
	cin >> num;
	for (auto i = 2; i <= num; ++i) {
		ListNode* current = new ListNode(i);
		ListNode* pos = head;
		while (pos->next != NULL) {
			pos = pos->next;
		}
		pos->next = current;
	}	
	int d_pos;
	cin >> d_pos; 
	// ListNode* head = new ListNode(1);
	Solution s;
	ListNode* del = s.removeNthFromEnd(head,d_pos);
	//ListNode* del = s.removeNthFromEnd(head, 1);
	while (del->next != NULL) {
		cout << del->val;
		if (del->next != NULL) cout << "->";
		del = del->next;
		
	}
	cout <<del->val << endl;
	return 0;
}