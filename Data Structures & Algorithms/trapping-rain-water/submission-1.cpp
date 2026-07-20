class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int area = 0;
        while(left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(leftMax < rightMax) {
                area += leftMax - height[left];
                left++;
            } else {
                area += rightMax - height[right];
                right--;
            }
        }
    return area;
    }
};