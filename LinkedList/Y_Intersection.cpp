/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//TC - O(N1+2*N2)
class Solution {
private:
    int findLen(ListNode* temp){
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* findIntersection(ListNode* h1,ListNode* h2,int diff){
        while(diff>0){
            h2=h2->next;
            diff--;
        }
        while(h1!=NULL){
            if(h1==h2) return h1;
            h1=h1->next;
            h2=h2->next;
        }
        return h1;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=findLen(headA);
        int lenB=findLen(headB);
        if(lenA<lenB){
            return findIntersection(headA,headB,lenB-lenA);
        }
        else return findIntersection(headB,headA,lenA-lenB);
        return NULL;
    }
};


//TC - O(N1+N2)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *temp1=headA,*temp2=headB;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2) return temp1;
            if(temp1==NULL) temp1=headB;
            if(temp2==NULL) temp2=headA;
        }
        return temp1;
    }
};
