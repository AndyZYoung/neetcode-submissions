class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>nums;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num1 = nums.top(); nums.pop();//pop不返回值 要先赋值
                int num2 = nums.top(); nums.pop();  
                int result;
                if(tokens[i] == "+") result = num2 + num1;//顺序！
                else if(tokens[i] == "-") result = num2 - num1;
                else if(tokens[i] == "*") result = num2 * num1;
                else if(tokens[i] == "/") result = num2 / num1;
                nums.push(result);
            }else{
                nums.push(stoi(tokens[i]));
            }
        }
    return nums.top();
    }
};