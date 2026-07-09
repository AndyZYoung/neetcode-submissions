class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> count(26,0); //一个26个0的数组
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            //比如s[1]字符串里面的第二个字符是b,那么也就是count['b'-'a']即count[1]，记录了字符串里面b出现的次数
            count[t[i] - 'a']--;
        }
        for(int x : count){
            if(x != 0){
                return false;
            }
        }
        return true;
    }
};
