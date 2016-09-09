#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		vector<int> merge;
		ListNode* p = l1;
		while (p != NULL) {
			merge.push_back(p->val);
			p = p->next;
		}
		ListNode* q = l2;
		while (q != NULL) {
			merge.push_back(q->val);
			q = q->next;
		}
		if (merge.size() == 0) return NULL;
		sort(merge.begin(),merge.end());
		ListNode* mergetwolist = new ListNode((*merge.begin()));
		for (int i = 1; i < merge.size(); ++i) {
			ListNode* current = new ListNode(merge[i]);
			ListNode* pos = mergetwolist;
			while (pos->next != NULL) {
				pos = pos->next;
			}
			pos->next = current;
		}
		return mergetwolist;
	}
};
