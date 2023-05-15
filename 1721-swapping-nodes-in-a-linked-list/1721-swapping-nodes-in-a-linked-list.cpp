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
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp = head, *a = head, *b = head;

        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        if(n<=1) return head; // n = 5
        
        int K = n - k + 1; // K = 4
        
        temp = head;
        //k = 1, K = 2
        int i = 1;
        while(temp!=NULL and i <= n){
            if(i == k) a = temp;
            if(i == K) b = temp;
            i++;
            temp = temp->next;
        }
        // int t = a->val;
        // a->val = b->val;
        // b->val = t;
        swap(a->val, b->val);
        
        return head;
    }
};