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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int c=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        vector<ListNode*> ans(k,NULL);
            int j=c%k;
            int n=c/k;
            int i=0;
            temp=head;
            while(j--)
            {
                int x=n+1;
                ans[i]=temp;
                ListNode *prev=NULL;
                while(temp!=NULL && x--){
                    prev=temp;
                    temp=temp->next;
                }
                prev->next=NULL;
                i++;
                
            }
            while(i<ans.size()){
                int x=n;
                ans[i]=temp;
                ListNode*prev=NULL;
                while(temp!=NULL && x--){
                    prev=temp;
                    temp=temp->next;
                }
                if(prev!=NULL) prev->next=NULL;
                i++;
        }
     
        return ans;
    }
};