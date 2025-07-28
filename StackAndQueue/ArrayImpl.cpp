//Stack Using Arrays
class StackImpl{
    private:
    int Top=-1,Size=10;
    int stack[10];

    public:
    void push(int x){
        if(Top==Size){
            cout<<"Stack is Full"<<endl;
            return;
        }
        Top++;
        stack[Top]=x;
    }
    void pop(){
        if(Top==-1) cout<<"Stack is empty"<<endl;
        Top--;
    }
    int top(){
        if(Top==-1) return -1;
        return stack[Top];
    }
    int size(){
        return Top+1;
    }
};


//Queue Using Arrays
class QueueImpl{
    private:
    int start=-1,end=-1;
    int Size=10,currSize=0;
    int queue[10];

    public:
    void push(int x){
        if(currSize==Size){
            cout<<"Queue is Full"<<endl;
            return;
        }
        if(start==-1 && end==-1){
            start=0,end=0;
        }
        else{
            end=(end+1)%Size;
        }
        queue[end]=x;
        currSize++;
    }
    int pop(){
        if(start==-1){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        if(start==end){
            start=-1,end=-1;
        }
        else start=(start+1)%Size;
        currSize--;
    }
    int top(){
        if(start==-1){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return queue[start];
    }
    int size(){
        return currSize;
    }
};
