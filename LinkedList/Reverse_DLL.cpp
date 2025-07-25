/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head==NULL || head->next==NULL) return head;
        DLLNode *curr=head,*back=NULL;
        while(curr){
            DLLNode* front=curr->next;
            curr->prev=front;
            curr->next=back;
            if(back) back->prev=curr;
            back=curr;
            curr=front;
        }
        return back;
        
    }
};
