/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i] 是 以 nums[i] 结尾的 LIS 长度
        // dp[i] = max(dp[i], dp[j] + 1) for i > j and nums[i] > nums[j]

        for(int i = 1; i<n; ++i){
            for(int j = 0; j<i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = dp[i] > dp[j]+1 ? dp[i] : dp[j]+1;
                }
            }
        }

        int ans = -1;
        for(int i = 0; i<n; ++i){
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};
// @lc code=end

