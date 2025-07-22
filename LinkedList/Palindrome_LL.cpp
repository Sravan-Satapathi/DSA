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

//TC - O(2N) , SC - O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(!st.empty()){
            int data=st.top();
            st.pop();
            if(data!=temp->val) return false;
            temp=temp->next;
        }
        return true;
    }
};


//TC - O(2N) , SC - O(1)
class Solution {
private:
    ListNode* reverseLL(ListNode* head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* newHead=reverseLL(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        ListNode *slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverseLL(slow->next);
        slow->next=newHead;
        ListNode *first=head,*second=newHead;
        while(second!=nullptr){
            if(first->val!=second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;
    }
};
