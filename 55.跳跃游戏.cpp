/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int lastzero = -1;

        if(len <= 1){
            return true;
        }
        nums[len-1] = 1;


        for(int i = len-1; i >= 0; --i){
            if(nums[i]==0){
                lastzero = lastzero>i?lastzero:i;
            } 

            if(i + nums[i] > lastzero){
                lastzero = -1;
            }
        }

        if(lastzero == -1){
            return true;
        }
        return false;
    }
};
// @lc code=end

