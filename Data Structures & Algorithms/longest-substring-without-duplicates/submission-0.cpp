class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> cnt;//一开始就定义好了 key是char value是int
    int left=0;
    int ans=0;
    for(int right=0; right<s.size();right++){
        char n = s[right];
        cnt[n]++;
        while(cnt[n]>1){
            cnt[s[left]]--;
            left++;
       }
       ans = max(ans, right - left + 1);  // ← 窗口长度 = 右 - 左 + 1
    }
    return ans;
    }
};
/*
如果需要返回最长且不重复的字符串
if (right - left + 1 > maxLen) {
    maxLen = right - left + 1;
    start = left;  // ← 记录当前窗口起点
}
return s.substr(start, maxLen);  // ← 用substr截取
*/