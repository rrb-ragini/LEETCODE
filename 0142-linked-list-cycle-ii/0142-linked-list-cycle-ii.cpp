/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *rabbit = head, *tortoise=head;
        
        while(rabbit!=NULL and rabbit->next!=NULL){
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
            
            if(rabbit==tortoise){
                tortoise = head;
                
                while(rabbit!=tortoise){
                    rabbit = rabbit->next;
                    tortoise = tortoise->next;
                }
                return tortoise;
            }
        }
        
        return NULL;
    }
};