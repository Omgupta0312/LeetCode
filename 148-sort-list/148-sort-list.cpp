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
  ListNode* findMid(ListNode* root){  // method to find mid element in a linked list
       ListNode* slow = root , *fast = root; 
        while(fast->next !=NULL && fast->next->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;  }
    
    
    ListNode* merge(ListNode* left,ListNode* right){// to merge two linkedList in asecending order
        
        ListNode* ptr = new ListNode(0); //  first node which will be used to return head of merged list
        ListNode* curr = ptr;
        while(left!= NULL && right!= NULL){
            if(left->val >  right->val){
                curr->next = right;
                right = right->next;
            }
            else {
                curr->next = left ;
                left = left->next;
            }
            curr = curr->next;
        }
        
        if(left!=NULL){ // copy the remaining elements into merge list
            while(left!=NULL){
                curr->next = left;
                left = left->next;
                curr = curr->next;
            }
        }
        if(right !=NULL){
            while(right!=NULL){
                curr->next = right;
                right = right ->next;
                curr= curr->next;
            }
        }
        return ptr->next; // pointer to first node of merge list
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL ||  head->next == NULL){ // base case for recursion
            return head;
        }
        ListNode* mid = findMid(head);// finding middle element 
        ListNode*   MidNext = mid->next;  
        mid->next = NULL; // dividing a linked list into 2 list by breaking from middle 
        ListNode* temp = head;
        ListNode* tem = MidNext;
        ListNode*  left =  sortList(head);
        ListNode*  right = sortList(MidNext);
    
        return  merge(left, right);
    }

};