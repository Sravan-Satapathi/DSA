/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Detect Cycle
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};


//Find length of cycle if exists
class Solution {
public:
    int lengthOfCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                int count=1;
                fast=fast->next;
                while(fast!=slow){
                    fast=fast->next;
                    count++;
                }
                return count;
            }
        }
        return 0;
    }
};
