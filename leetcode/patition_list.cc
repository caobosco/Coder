#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy, *cur = head;
        while(cur &&cur->val < x ) {
            pre = pre->next;
            cur = cur->next;
        }
        while (cur) {
            if (cur->val >= x) 
                cur= cur->next;
            else {
                ListNode *tmp = cur->next;
                cur->next = pre->next;
                pre->next = cur;
                cur = tmp;
            }
        }
        return dummy.next;
    }
};

int main(){
    ListNode a(2), b(1);
    a.next = &b;
    Solution sol;
    sol.partition(&a, 2);
    return 0;
}
