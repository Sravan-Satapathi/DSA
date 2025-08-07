class LRUCache {
private:
    class Node{
    public:
        int key,value;
        Node *next,*prev;
        Node(int key,int value){
            this->key=key;
            this->value=value;
            this->prev=nullptr;
            this->next=nullptr;
        }
    };

    Node *head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mpp;
    int capacity;

    void deleteNode(Node* node){
        Node* before=node->prev;
        Node* after=node->next;
        before->next=after;
        after->prev=before;
    }
    void insertAfterHead(Node* node){
        Node* currAfter=head->next;
        head->next=node;
        node->prev=head;
        node->next=currAfter;
        currAfter->prev=node;
    }
    
public:
    LRUCache(int capacity) {
        mpp=unordered_map<int,Node*>();
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->value=value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            Node* node=new Node(key,value);
            mpp[key]=node;
            insertAfterHead(node);
        }

        if(mpp.size()>capacity){
            Node* node=tail->prev;
            deleteNode(node);
            mpp.erase(node->key);
            delete node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
