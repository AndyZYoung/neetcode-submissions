class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());//排序，直接修改原数组nums
        vector<vector<int>> output;
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
            int target = -nums[i];
            int sum=nums[left]+nums[right];
                if(sum == target){
                    output.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left] == nums[left+1])left++;//停留在最后一个重复元素的位置
                    while(left<right && nums[right] == nums[right-1])right--;
                    left++;
                    right--;
                }else if(sum<target){
                    left++;
                }else{
                    right--;
                }
            }
        }
    return output;
    }
};