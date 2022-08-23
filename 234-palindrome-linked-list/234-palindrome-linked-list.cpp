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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head, *prev=NULL;
        bool flag = false;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            ListNode *curr=slow;
            slow=slow->next;
            curr->next = prev;
            prev = curr;
            
            if(fast == NULL)
                flag = true;
                
        }
        if(!flag) slow = slow->next;
        while(slow!=NULL && prev!=NULL)
        {
            if(slow->val != prev->val)
                return false;
            
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};