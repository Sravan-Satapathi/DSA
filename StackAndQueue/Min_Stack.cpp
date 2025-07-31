class MinStack {
private:
    stack<long long> st;
    long long mini;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<=mini){
                st.push(1LL*2*val-mini);
                mini=val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        long long curr=st.top();
        if(curr<mini){
            mini=2*mini-curr;
        }
        st.pop();
    }
    
    int top() {
        long long curr=st.top();
        if(curr<mini) return int(mini);
        return int(curr);
    }
    
    int getMin() {
        return int(mini);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
