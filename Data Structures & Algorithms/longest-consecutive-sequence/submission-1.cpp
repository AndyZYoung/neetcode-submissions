class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());//这个和下面注释的是完全一样的功能，但是这个是先分配再放入，如果重复的元素多那下面的内存开销会少
        /*unordered_set<int> numSet;
        for(int num : nums){
            numSet.insert(num);//push_back适用于vector,string,list线性序列容器
            //重复元素自动忽略
        }*/
        //完成去重
        int longest = 0;
        for(int num : numSet){
            if(numSet.count(num-1) == 0){//是首位
                int currentNum = num;
                int currentStreak = 1;
                while(numSet.count(currentNum+1)){//有下一个数字
                    currentNum++;
                    currentStreak++;
                }
                longest = max(longest,currentStreak);
            }
        }
    return longest;
    }
};
