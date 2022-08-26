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
    int getDecimalValue(ListNode* head) {
        string bin="";
        while(head!=NULL)
        {
            if(head->val==1)
                bin+='1';
            else bin+='0';
            head=head->next;
        }
       return std::stoi(bin, nullptr, 2);
    }
};