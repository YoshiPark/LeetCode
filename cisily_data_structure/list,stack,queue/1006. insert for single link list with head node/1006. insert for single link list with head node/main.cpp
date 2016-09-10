#include <iostream>
using namespace std;
struct ListNode {
	int data;
	ListNode *next;
};
class List
{
public:
	List()
	{
		head = new ListNode;
		head->next = NULL;
	}

	~List()
	{
		ListNode* curNode;
		while (head->next)
		{
			curNode = head->next;
			head->next = curNode->next;
			delete curNode;
		}
		delete head;
	}
	/*我的代码void insert(int toadd, int pos) {
		ListNode* p = head;
		int m_count = 1;
		while (p->next != NULL) {
			p = p->next;
			m_count++;
		}
		if (pos <= 0 || pos > m_count) return;
		int t_pos = 0;
		ListNode* q = head;
		while (t_pos < pos - 1) {
			q = q->next;
			t_pos++;
		}
		ListNode* temp = new ListNode;
		temp->data = toadd;
		temp->next = q->next;
		q->next = temp;
	} */
	/* 嘉昕代码void insert(int toadd, int pos) {
		int cnt = 0;
		ListNode *tempf = head;
		ListNode *th = head;
		while (th) {
			th = th->next;
			cnt++;
		}
		if (pos <= 0 || pos > cnt) return;
		pos--;
		while (pos--) {
			tempf = tempf->next;
		}
		ListNode *tempb = tempf->next;
		tempf->next = new ListNode;
		tempf->next->data = toadd;
		tempf->next->next = tempb;
	} */
	void insert(int toadd, int pos) {
		if (NULL != head) {
			int size = 1;
			ListNode * p = head->next;
			while (NULL != p) {
				size++;
				p = p->next;
			}

			if (pos > 0 && pos <= size) {
				p = head;
				for (int i = 0; i < pos - 1; i++) {
					p = p->next;
				}
				ListNode* hold = new ListNode();
				hold->data = toadd;
				hold->next = p->next;
				p->next = hold;
			}
		}
	}

private:
	ListNode* head;
};
int main() {
	List l1;
	l1.insert(1, 1);
	l1.insert(12, 1);
	l1.insert(2, 2);
	l1.insert(3, 3);
	l1.insert(10, 2);
	return 0;
}