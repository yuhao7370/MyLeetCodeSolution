/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int checkMul(int ans, int isMinus){
        int intMax = 2147483647;
        if(ans > (intMax) / 10){
                return false;
            }

        return true;
    }

    int checkAdd(int ans, int isMinus){
        return (ans <= ans + isMinus);
    }

    int reverse(int x) {
        int intMax = 2147483647;
        int ans = 0;
        int isMinus = x > 0 ? 0 : 1;
        if(x == -intMax - 1){
            return 0;
        }
        if(isMinus){
            x = -x;
        }
        while(x > 0){
            if(!checkMul(ans, isMinus))
                return 0;
            
            ans *= 10;

            if(!checkAdd(ans, isMinus))
                return 0;

            ans += x % 10;

            x /= 10;
        }

        return isMinus ? -ans : ans;
    }
};
// @lc code=end

