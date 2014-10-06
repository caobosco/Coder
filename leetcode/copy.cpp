#include <cstdio>

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

class Solution {
    //RandomListNode *construct(RandomListNode )
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        RandomListNode *node = head;
        
        while(node){
            RandomListNode *tmp = new RandomListNode(node->label);
            tmp->next = node->next;
            node->next = tmp;
            node = tmp->next;
        }
        
        node = head;
        while(node){
            if(node->random)
                node->next->random = node->random->next;
            node = node->next->next;
        }
        
        node = head;
        RandomListNode *ret = node->next, *irt = node->next;
        node->next = node->next->next;
        node = node->next;
        while(node){
            irt->next = node->next;
            node = node->next->next;
            irt = irt->next;
        }
        return ret;
    }
};

int main(){
    Solution sol;
    RandomListNode *head = new RandomListNode(-1);
    sol.copyRandomList(head);
    return 0;
}
