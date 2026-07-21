class Solution {
public:
    char getMatchingOpen(char c){
            if(c == ')') return '(';
            if(c == ']') return '[';
            if(c == '}') return '{';
            return '\0';  // 默认返回空字符
    }
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c =='('|c =='['|c =='{'){
                st.push(c);
            }else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                if(top == getMatchingOpen(c)){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
    return st.empty();//如果是空的那就是return true
    }
};
//st.push(val) 把val放在栈顶
//st.pop()     拿走栈顶元素
//st.top()     看一眼栈顶是什么
//st.empty()   检查栈有没有元素
//st.size()    看一下栈里面有多少元素