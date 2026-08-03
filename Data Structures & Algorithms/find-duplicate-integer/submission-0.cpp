class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //原始的想法是使用unordered_set<int> seen;记录元素是否出现过 但是现在需要能够O(1)的额外空间要求
        //题目：n+1个元素，每个元素只能是[1,n]，所以一定有重复元素，而且说了有且仅有一个重复元素
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        int finder=0;//寻找环入口
        //因为重复导致进入环，所以环入口的下标即为重复元素的元素值
        while(finder!=slow){
            finder=nums[finder];
            slow=nums[slow];//从之前的环中走
            //无论相遇点是环内的点还是恰好是环入口，再这样走一次一定会在环入口相遇
        }//这个循环最先找到的就是环入口
        //无论相遇点是在环内还是环入口 这一次循环再让slow走一圈同样的距离 最后一定会走到环入口处
        return finder;//注意这个下标就是重复的元素的元素值
        //nums[finder]就不对了
    }
};
