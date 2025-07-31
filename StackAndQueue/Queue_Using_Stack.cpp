//Approach 1
class MyQueue {
private:
    stack<int> st1,st2;
public:
    MyQueue() {
    }
    //TC - O(2N)
    void push(int x) {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int el=st1.top();
        st1.pop();
        return el;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};


//Approach 2
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> st1,st2;
public:
    MyQueue() {
    }
    //TC - O(1)
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int el=st2.top();
            st2.pop();
            return el;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int el=st2.top();
        st2.pop();
        return el;
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};
