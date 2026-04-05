#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> leftmax(len, 0), rightmax(len, 0);
        for(int i=1; i<len; ++i){
            leftmax[i] = max(leftmax[i-1], height[i-1]);
        }
        for(int i=len-2; i>0; --i){
            rightmax[i] = max(rightmax[i+1], height[i+1]);
        }

        int ans = 0;
        for(int i=0; i<len; ++i){
            ans += max(0, min(leftmax[i], rightmax[i]) - height[i]);
        }

        return ans;
    }
};
// @lc code=end

