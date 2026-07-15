class Solution {
public:
    //字符串长度 + "#" + 真字符串 这样就算字符串里面包含如#5也没问题,但是这个顺序不能反了
    string encode(vector<string>& strs) {
        string res;
        for(string& s : strs){//引用避免了拷贝
            int size = s.size();
            res += to_string(size) + "#" + s;
        }
        return res;
    }
    //只能传字符串,不能传列表
    vector<string> decode(string s) {
        int i = 0;
        vector<string> result; 
        while(i<s.size()){
            size_t pos = s.find('#',i);//size_t 是无符号类型
            //字符串s中从位置pos开始，查找 # 第一次出现的位置 index赋值给pos 从0开始计
            string len_str = s.substr(i,pos-i);//从索引i开始截pos-i位,(pos-i)是要截取的长度
            //对string s = "2#Hello"; s.substr(2, 5); 结果是"Hello"
            int len = stoi(len_str);
            string str = s.substr(pos+1,len);
            result.push_back(str);
            i = pos + len + 1; 
        }
        return result;
    }
};
