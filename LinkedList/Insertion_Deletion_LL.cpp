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

//Traversal
void Traversal(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* deleteHead(Node* head){
    if(head==nullptr) return nullptr;
    Node* temp=head;
    head=head->next;
    temp->next=nullptr;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node *prev=nullptr,*curr=head;
    while(curr->next!=nullptr){
        prev=curr;
        curr=curr->next;
    }
    prev->next=nullptr;
    free(curr);
    return head;
}

Node* deleteIndex(Node* head,int index){
    if(head==nullptr) return nullptr;
    if(index==0){
        Node* temp=head;
        head=head->next;
        temp->next=nullptr;
        free(temp);
        return head;
    }
    int count=0;
    Node *curr=head,*prev=nullptr;
    while(curr!=nullptr){
        if(count==index){
            prev->next=curr->next;
            curr->next=nullptr;
            free(curr);
            break;
        }
        count++;
        prev=curr;
        curr=curr->next;
    }
    return head;
}

Node* deleteElement(Node* head,int val){
    if(head==nullptr) return nullptr;
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        temp->next=nullptr;
        free(temp);
        return head;
    }
    Node *curr=head,*prev=nullptr;
    while(curr!=nullptr){
        if(curr->data==val){
            prev->next=curr->next;
            curr->next=nullptr;
            free(curr);
            return head;
        }
        prev=curr;
        curr=curr->next;
    }
    return head;
}


Node* insertHead(Node* head,int val){
    if(head==nullptr) return new Node(val);
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;
    return head;
}

Node* insertTail(Node* head,int val){
    if(head==nullptr) return new Node(val);
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}

Node* insertIndex(Node* head,int val,int index){
    if(head==nullptr){
        if(index==0) return new Node(val);
        return nullptr;
    }
    if(index==0){
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
        return head;
    }
    int count=0;
    Node *curr=head,*prev=nullptr;
    while(curr!=nullptr){
        if(count==index){
            Node* newNode=new Node(val);
            newNode->next=curr;
            prev->next=newNode;
            return head;
        }
        count++;
        prev=curr;
        curr=curr->next;
    }
    return head;
}
