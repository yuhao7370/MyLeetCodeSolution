/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if(val >= 51){
            return len;
        }

        int k = 0;

        for(int i = 0; i < len; ++i){
            if(nums[i] != val){
                nums[k] = nums[i];
                ++k;
            }
        }


        return k;
    }
};
// @lc code=end

