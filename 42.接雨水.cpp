/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // TODO 优化，别他妈暴力了
        int n = height.size();
        int maxheight = -1;
        int heightsum = 0;
        for (int i = 0 ;i < n; ++i){
            maxheight = maxheight > height[i] ? maxheight : height[i];
            heightsum += height[i];
        }

        int sum = 0;
        int lp, rp;
        for (int i = 0; i <= maxheight; ++i){
            lp=0, rp=n-1;
            while(height[lp] < i){
                ++lp;
            }
            while (height[rp] < i)
            {
                --rp;
            }

            sum += lp + (n - rp - 1);
        }

        return maxheight * n - sum - heightsum;
    }
};
// @lc code=end

