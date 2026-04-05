#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check;
        for(int i = 0; i < nums.size(); ++i){
            check.insert(nums[i]);
        }

        int ans = 0;

        for (int x : check) {
            if (check.find(x - 1) != check.end()) {
                continue;
            }

            int cur = x;
            int tmpans = 1;

            while (check.find(cur + 1) != check.end()) {
                ++cur;
                ++tmpans;
            }

            ans = max(ans, tmpans);
        }

        return ans;
    }
};
// @lc code=end

