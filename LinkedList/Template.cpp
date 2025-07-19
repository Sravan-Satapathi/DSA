#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    public:
    Node(int val){
        this->val=val;
        this->next=nullptr;
    }
};

Node* arrayToLL(vector<int>& nums){
    Node* head=new Node(nums[0]);
    Node* temp=head;
    for(int i=1;i<nums.size();i++){
        Node* curr=new Node(nums[i]);
        temp->next=curr;
        temp=curr;
    }
    return head;
}

void traversal(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main(){
    vector<int> nums={1,2,3,4,5};
    Node* head=arrayToLL(nums);
    traversal(head);
    return 0;
}
