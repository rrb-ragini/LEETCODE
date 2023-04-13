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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        int a, b;
        while(list1!=NULL and list2!=NULL){
            a = list1->val;
            b = list2->val;
            ListNode *temp1;
            if(a<=b){
                temp1=list1;
                list1=list1->next;
            }
            else if (b<a){
                temp1 = list2;
                list2=list2->next;
            }
            temp->next = temp1;
            temp = temp1;
            
        }
        if(list1==NULL)
            temp->next = list2;
        else if(list2==NULL)
            temp->next = list1;
        
        return head->next;
    }
};