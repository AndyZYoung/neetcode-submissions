class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;//mp[value]返回的是index
        for(int i=0;i<nums.size();i++){
            int y = target - nums[i];
            if(mp.count(y)!=0){//if(mp.count(y)){ 逻辑是一样的 0:没找到y 1:找到了y 
                return{mp[y],i};//注意这里的顺序i是最新的，找的是旧的mp[y]，所以先输出mp[y]再是i
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
//Hashmap 复杂度更低
//Hashmap:map[value]=key,数组Vector:nums[key]=value,由自己定义
//比如这里我是定义的mp[nums[i]] = i 即mp[value] = index