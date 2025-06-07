/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int mymin(int a, int b){
        return a < b ? a : b;
    }

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        // dp[i][j] 是 word1[0~i-1] 与 word2[0~j-1] 的最小编辑距离
        // dp[0][j] = j, word[i][0] = i
        for(int i = 0; i <= m; ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; ++j){
            dp[0][j] = j;
        }


        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else{
                    dp[i][j] = mymin(mymin(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

