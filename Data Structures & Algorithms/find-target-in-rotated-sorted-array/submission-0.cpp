class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(nums[mid]==target){//先判断是左侧还是右侧有序
                return mid;
            }
            if(nums[left]<=nums[mid]){
                if(target>=nums[left] && target<nums[mid]){//注意哪里可以取等号 哪里不用
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(target<=nums[right] && target>nums[mid]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
    return -1;
    }
};