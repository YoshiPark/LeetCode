#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		bool in = true;
		ListNode* pos = head;
		ListNode* count = head;
		int n_count = 1;
		while (count->next != NULL) {
			n_count++;
			count = count->next;
		}
		int true_pos = n_count - n;
		if (true_pos == 0) {
			ListNode* del = head;
			head = head->next;
			delete del;
			return head;
		}
		else
		{
			int n_pos = 0;
			while (n_pos < true_pos - 1) {
				n_pos++;
				pos = pos->next;
				if (pos->next == NULL) {
					in = false;
					break;
				}
			}
			if (in == true && head->next != NULL) {
				ListNode* del_prev = pos;
				ListNode* del = del_prev->next;
				del_prev->next = del->next;
				delete del;
				return head;
			}
			else
			{
				return NULL;
			}
		}
	}
};
