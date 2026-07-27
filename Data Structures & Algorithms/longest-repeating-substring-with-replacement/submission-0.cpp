class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,maxcnt=0,ans=0;
        vector<int> cnt(26,0);
        for(int right=0;right<s.size();right++){
            cnt[s[right]-'A']++;
            maxcnt = max(cnt[s[right]-'A'],maxcnt);
            while(right-left+1-maxcnt>k){
                cnt[s[left]-'A']--;
                left++;
            }
            ans=max(right-left+1,ans);
        }
    return ans;
    }
};