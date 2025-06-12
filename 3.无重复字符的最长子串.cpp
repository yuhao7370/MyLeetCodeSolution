#include<string>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> check(256, 0);
        int lp = 0, rp = 0;
        int len = s.length();
        int ans = 0;

        while (rp < len) {
            char c = s[rp];
            check[c]++;
            while (check[c] > 1) {
                check[s[lp]]--;
                lp++;
            }
            ans = ans > rp - lp ? ans : rp - lp + 1;
            rp++;
        }
        return ans;
    }
};
// @lc code=end

