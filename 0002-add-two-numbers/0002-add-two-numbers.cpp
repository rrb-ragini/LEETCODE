/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* head;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int counter = 0; 
        int a, b, c;

            head = nullptr;
        ListNode *curr = nullptr;
        while(l1!=NULL or l2!=NULL or counter !=0){
            a = l1?l1->val:0;
            b = l2?l2->val:0;
            c = a + b + counter;
            counter = c/10; 
            ListNode *temp = new ListNode(c%10);
                        if (curr) {
                curr->next = temp;
                curr = curr->next;
            } else {
                head = temp;
                curr = head;
            }

            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
        }    

        return head;
    }
};