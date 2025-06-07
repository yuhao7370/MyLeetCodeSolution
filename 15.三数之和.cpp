#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<map>
#include<algorithm>
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
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int lp, rp;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            // 接下来在 i+1 到末尾区间中查找两数之和为 -nums[i] 的二元组
            lp = i+1, rp = nums.size() - 1;
            
            
            while(lp < rp){
                if(nums[lp] + nums[rp] > -nums[i]){
                    --rp;
                } else if (nums[lp] + nums[rp] < -nums[i]){
                    ++lp;
                } else{
                    ans.push_back({nums[i], nums[lp], nums[rp]});
                    while (lp < rp && nums[lp] == nums[lp + 1]) ++lp;
                    while (lp < rp && nums[rp] == nums[rp - 1]) --rp;
                    ++lp;
                    --rp;
                }
                
            }
        }

        return ans;
    }
};
// @lc code=end

