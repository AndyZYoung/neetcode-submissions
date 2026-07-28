class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)!=0) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if (need.count(d)!=0) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    /*等价于
        if (len == INT_MAX) {
            return "";
        } else {
            return s.substr(start, len);
        }
    */
    }
};