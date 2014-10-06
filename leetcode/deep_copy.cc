#include <cstdio>

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return head;
        RandomListNode *cur = head, *next;
        while (cur) {
            next = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = next;
            cur = next;
        }
        
        cur = head;
        while (cur && cur->next) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        
        next = head->next;
        while (head) {
            cur = head->next;
            head->next = head->next->next;
            head = head->next;
            cur->next = head->next;
            cur = cur->next;
        }
        return next;
    }
};

int main() {
    RandomListNode *example = new RandomListNode(-1);
    Solution sol;
    sol.copyRandomList(example);
    return 0;
}   
