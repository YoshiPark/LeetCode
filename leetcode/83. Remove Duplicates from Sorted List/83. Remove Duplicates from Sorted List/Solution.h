#define NULL 0
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		auto p = head;
		auto q = head->next;
		while (q != NULL) {
			if (p->val == q->val) {
				auto temp = q;
				q = q->next;
				p->next = q;
				delete temp;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		return head;
	}
};