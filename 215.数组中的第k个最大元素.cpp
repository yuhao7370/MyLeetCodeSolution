#include<iostream>
#include<vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> tong(20007);
        int max_with_num = 0;
        int min_with_num = 20007;
        for(int i = 0; i < nums.size(); ++i){
            ++tong[nums[i] + 10000];
            max_with_num = max_with_num > nums[i] + 10000 ? max_with_num : nums[i] + 10000;
            min_with_num = min_with_num < nums[i] + 10000 ? min_with_num : nums[i] + 10000;
        }

        for(int i = max_with_num; i >= min_with_num; --i){
            k -= tong[i];
            if(k<=0){
                return i - 10000;
            }
        }

        return nums[0];
    }
};
// @lc code=end

int main(){
    Solution Sol;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    int k = 1;
    cout << Sol.findKthLargest(nums, k);
}
