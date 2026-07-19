#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            if(!isalnum(s[left])){
                left++;
                continue;//没有continue就不会回到while的开头来重新检查了，必须有continue
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left]) == tolower(s[right])){
                left++;
                right--;
            }else{
                return false;
            }
        }
    return true;
    }
};
