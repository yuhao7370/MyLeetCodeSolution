#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int slow = nums[0];
        int fast = nums[0];

        if(n==1){
            return nums[0];
        }

        slow=nums[slow];
        fast=nums[nums[fast]];

        int meet;
        while(true){
            if(slow == fast){
                meet = slow;
                break;
            }
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = meet;
        fast = nums[0];

        while(true){
            if(slow == fast){
                return slow;
            }
            slow = nums[slow];
            fast = nums[fast];
        }
    }
};
// @lc code=end

