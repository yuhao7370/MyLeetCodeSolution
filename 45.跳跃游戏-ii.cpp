/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int bound = nums.size() - 1;
        int count = 0;

        while(bound > 0){
            for(int i = 0; i <= bound; ++i){
                if(i + nums[i] >= bound){
                    bound = i;
                    break;
                }
            }
            ++count;
        }
        return count;
    }
};
// @lc code=end

