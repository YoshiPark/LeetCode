#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a[1000] = {0};
        int b[1000] = {0};
        int a_count = 0, b_count = 0;
        ListNode* p =l1;
        while (p != NULL) {
            a[a_count++] = p->val;
            p = p->next;
        }
        ListNode* q = l2;
        while (q != NULL) {
            b[b_count++] = q->val;
            q = q->next;
        }
        for (auto i = 0; i < a_count/2; ++i) swap(a[i], a[a_count - i - 1]);
        for (auto i = 0; i < b_count/2; ++i) swap(b[i], b[b_count - i - 1]);
        int c[1000] = {0};
        int min_size = a_count > b_count ? b_count:a_count;
        int max_size = a_count > b_count ? a_count:b_count;
        bool temp;
        if (a_count > b_count) temp = true;
        for (auto i = 0; i < min_size; ++i) {
            c[i] += a[i] + b[i];
            if (c[i] >= 10) {
              c[i+1] += c[i] / 10;
              c[i] %= 10;
            }
        }
        if (temp == true) {
          for (auto i = min_size; i < a_count; ++i) {
            c[i] += a[i];
            if (c[i] >= 10) {
              c[i+1] += c[i] / 10;
              c[i] %= 10;
            }
          }
        } else {
          for (auto i = min_size; i < b_count; ++i) {
            c[i] += b[i];
            if (c[i] >= 10) {
              c[i+1] += c[i] / 10;
              c[i] %= 10;
            }
          }
        }
        ListNode* head;
        ListNode* r;
        int i = 0;
        while (i <= max_size) {
          if (i == 0) {
            head = new ListNode(c[i]);
            r = head;
          } else {
            if (i != max_size || (i == max_size && c[i] != 0)) {
              r->next = new ListNode(c[i]);
              r = r->next;
            }
          }
          i++;
        }
        return head;
    }
};
