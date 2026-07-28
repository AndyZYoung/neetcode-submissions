class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for (int right = 0; right < nums.size(); right++) {
            // 1. 删除已经离开窗口的下标
            while (!dq.empty() && dq.front() < right - k + 1) {
                dq.pop_front();
            }
            // 2. 保持队列对应的数字单调递减
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }
            // 3. 加入当前下标
            dq.push_back(right);
            // 4. 完整窗口形成后，记录最大值
            if (right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};