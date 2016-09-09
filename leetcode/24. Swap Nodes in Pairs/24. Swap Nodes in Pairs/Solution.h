#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* new_head = head->next;
		head->next = new_head->next;
		new_head->next = head;
		new_head->next->next = swapPairs(new_head->next->next);
		return new_head;
	}
};
