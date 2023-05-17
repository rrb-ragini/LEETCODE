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
    int pairSum(ListNode* head) {
        stack<int>v;
        int n = 0;
        ListNode *temp = head;
        while(temp->next!=NULL){
            n++;
            temp = temp->next;
        }
        temp = head;
        int maxi = 0;
        for(int i =0; i <= n; ++i){
            if(i <=(n/2))
                v.push(temp->val);
            else{
                maxi = max(temp->val+v.top(), maxi);
                v.pop();
            }
            temp = temp->next;
        }
        
        // for(int i =0; i <=(n/2)-1; ++i){
        //     maxi = max(maxi, v[i] + v[n-i-1]);
        // }
        return maxi;
    }
};