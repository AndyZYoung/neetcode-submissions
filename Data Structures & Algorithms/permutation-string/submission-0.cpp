class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        vector<int> cnt(26,0),check(26,0);
        for(char s : s1)cnt[s-'a']++;
        int left=0;
        for(int right=0;right<s1.size();right++){
            check[s2[right]-'a']++;
        }
        if(check==cnt)return true;
        for(int i=s1.size();i<s2.size();i++){
            check[s2[i]-'a']++;
            check[s2[i-s1.size()]-'a']--;
            if(check==cnt)return true;
        }
    return false;
    }
};
//这里的窗口应该用固定的 s1是需要的字符串