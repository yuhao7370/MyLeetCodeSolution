#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0, right = len - 1;
        int ans = -1;

        while(left != right){
            ans = max(ans, (right - left) * min(height[left], height[right]));

            if(height[left] < height[right]){
                ++left;
            } else {
                --right;
            }
        }

        return ans;
    }
};
// @lc code=end

