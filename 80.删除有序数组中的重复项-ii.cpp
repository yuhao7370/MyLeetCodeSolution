#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int now = 1;
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[i-1]){
                cnt = 0;
            }

            if(cnt < 2){
                nums[now] = nums[i];
                ++now;
                ++cnt;
            }
        }

        return now;
    }
};
// @lc code=end
