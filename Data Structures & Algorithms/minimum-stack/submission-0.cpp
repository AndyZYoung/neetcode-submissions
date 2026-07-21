class MinStack {
private:
    stack<pair<int,int>> st;
public:
    MinStack(){
    }
    void push(int val){
        int currentMin;
        if(st.empty()){
            currentMin = val;
        }else{
            currentMin = min(st.top().second,val);
        }
        st.push({val,currentMin});
    }
    void pop(){
        st.pop();//不返回，直接删除栈顶元素
    }
    int top(){
        return st.top().first;
    }
    int getMin(){
        return st.top().second;
    }
};
