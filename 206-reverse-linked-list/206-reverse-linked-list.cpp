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
        ListNode* reverseList(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        
        ListNode* curr= head;
        ListNode* ptr = head;
        head = head->next;
        curr->next = NULL;
        while(head){
            curr = head;
            head = head->next;
            curr->next = ptr;
            ptr = curr;
        }
        return curr;
    }
};