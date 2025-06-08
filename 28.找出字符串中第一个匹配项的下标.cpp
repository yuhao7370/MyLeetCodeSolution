#include<string>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.length(), 0);
        int j = 0;

        for(int i = 1; i < needle.length(); ++i){
            while(j > 0 && needle[i] != needle[j]){
                j = next[j-1];
            }

            if(needle[i] == needle[j]){
                ++j;
            }
            next[i] = j;
        }

        int n = haystack.length();
        j = 0;
        for (int i = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                ++j;
            }
            if (j == needle.length()) {
                return i - needle.length() + 1; 
            }
        }

        return -1;
    }
};
// @lc code=end

