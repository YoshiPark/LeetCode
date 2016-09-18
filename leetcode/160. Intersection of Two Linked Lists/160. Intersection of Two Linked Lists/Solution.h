#define NULL 0
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		ListNode* p1 = headA;
		ListNode* q1 = headB;
		int l1 = 1, l2 = 1;
		while (p1->next != NULL) {
			p1 = p1->next;
			l1++;
		}
		while (q1->next != NULL) {
			q1 = q1->next;
			l2++;
		}
		if (p1 != q1) return NULL;
		if (l1 >= l2) {
			for (auto i = 0; i < l1 - l2; ++i) headA = headA->next;
		}
		else
		{
			for (auto i = 0; i < l2 - l1; ++i) headB = headB->next;
		}
		while (headA != headB) {
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}
};
