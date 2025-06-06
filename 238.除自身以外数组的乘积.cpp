/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> premult = nums, bckmult = nums;
        for(int i = 1; i < nums.size(); ++i){
            premult[i] *= premult[i-1];
        }
        for(int i = bckmult.size() - 2; i >= 0; --i){
            bckmult[i] *= bckmult[i+1];
        }
        

        vector<int> answer=nums;
        int temp;
        for(int i = 0; i < nums.size(); ++i){
            temp = 1;
            if(i>=1){
                temp *= premult[i-1];
            }
            if(i<nums.size()-1){
                temp *= bckmult[i+1];
            }
            answer[i] = temp;
        }
        return answer;
    }
};
// @lc code=end

