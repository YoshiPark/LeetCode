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
	void insert(int toadd, int pos) {
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
	}
private:
	ListNode* head;
};
int main() {
	List l1;
	l1.insert(1, 1);
	l1.insert(2, 2);
	return 0;
}