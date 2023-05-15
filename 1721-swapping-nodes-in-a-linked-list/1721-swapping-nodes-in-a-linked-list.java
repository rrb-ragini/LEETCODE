/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        int n = 0;
        ListNode temp = head, a = head, b = head;
        while(temp!=null){
            n++; temp = temp.next;
        }
        
        int K = n - k + 1;
        temp = head;
        int i = 1;
        while(temp!=null && i <= n){
            if(i == k) a = temp;
            if(i == K) b = temp;
            temp = temp.next;
            i++;
        }
        int t = a.val;
        a.val = b.val;
        b.val = t;
        
        
        return head;
    }
}