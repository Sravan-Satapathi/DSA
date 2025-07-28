class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        int len=q.size();
        q.push(x);
        for(int i=1;i<=len;i++){
            int el=q.front();
            q.pop();
            q.push(el);
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int curr=q.front();
        q.pop();
        return curr;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
