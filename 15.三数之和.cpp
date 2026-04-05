#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ansvec;
        int len = nums.size(), left, right;

        for(int i = 0; i < len; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            left = i + 1;
            right = len - 1;

            while(left < right){
                if(nums[left] + nums[right] > -nums[i]){
                    --right;
                } else if(nums[left] + nums[right] < -nums[i]){
                    ++left;
                } else{
                    ansvec.push_back({nums[i], nums[left], nums[right]});

                    ++left;
                    --right;

                    while(left < right && nums[left] == nums[left-1]) ++left;
                    while(left < right && nums[right] == nums[right+1]) --right;
                }
            }
        }
        return ansvec;
    }
};
// @lc code=end

