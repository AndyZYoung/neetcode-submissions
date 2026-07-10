class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        //bucket最多需要有bucket[max_frequency=num_size+1],当nums里面只有一个数字的时候,所以要+1
        //因为如bucket(2)就只有bucket[0],bucket[1]两个
        for (auto p : count) {
            int num = p.first;
            int freq = p.second;
            bucket[freq].push_back(num);
        }
        vector<int> result;
        for (int freq = bucket.size()-1; freq >= 0 ; freq--) {
            for(int num : bucket[freq]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
//nums = [1, 2, 2, 3, 3, 3]
//bucket[6] 空
//bucket[5] 空
//bucket[4] 空
//bucket[3] 有 [3] -> result = [3]
//bucket[2] 有 [2] -> result = [3, 2]
