/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* curr=head->next;
        while(curr){
            Node* back=curr->prev;
            if(curr->data==back->data){
                Node* front=curr->next;
                back->next=front;
                if(front) front->prev=back;
                Node* temp=curr;
                delete temp;
            }
            curr=curr->next;
        }
        return head;
    }
};
