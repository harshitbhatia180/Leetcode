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
    
    ListNode* add2DigitNcarry (ListNode* l1, ListNode* l2, int& c)
    {
        int val1 = l1? l1->val:0;           //0 if digit DNE
        int val2 = l2? l2->val:0;
        
        //cout<<val1<<"+"<<val2<<"+"<<c;      //debug
        int s = (val1 + val2 + c)%10;       //sum
        c = (val1 + val2 + c)/10;           //carry (update)
        
        //cout<<"="<<s<<"c"<<c<<endl;         //debug
        return new ListNode(s);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        auto curr = add2DigitNcarry(l1, l2, c);     //get first node outside of the loop
        auto head = curr;
        l1 = l1->next; l2 = l2->next;
        
        while (l1 || l2 || c)                       //keep adding till the end of both list and no more carry bit
        {
            curr->next = add2DigitNcarry(l1, l2, c);
            
            curr = curr->next;                      //move to next digit
            if (l1) l1 = l1->next; if (l2) l2 = l2->next;
        }
        
        return head;
    }
};