class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=nullptr;
    }
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

Node* sort(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* zero=new Node(-1);
    Node* one=new Node(-1);
    Node* two=new Node(-1);
    Node *zeroDummy=zero,*oneDummy=one,*twoDummy=two;
    Node* temp=head;
    while(temp){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    two->next=nullptr;
    one->next=twoDummy->next;
    zero->next=oneDummy->next;
    return zeroDummy->next;
}
