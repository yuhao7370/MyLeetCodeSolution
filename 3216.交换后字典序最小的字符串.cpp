/*
 * @lc app=leetcode.cn id=3216 lang=cpp
 *
 * [3216] 交换后字典序最小的字符串
 */

// @lc code=start
class Solution {
public:
    string getSmallestString(string s) {
        int length = s.length();
        int swapindex = -1;
        for(int i = 0; i + 1 < length; ++i){
            if((s[i] - '0' + s[i+1] - '0') % 2 == 0 && s[i] > s[i+1]){
                swapindex = i;
                swap(s[swapindex], s[swapindex+1]);
                break;
            }
        }
        return s;
    }
};
// @lc code=end

