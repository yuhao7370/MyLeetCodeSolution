
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        vector<int> ansvec;
        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i];

            if (ump.find(need) != ump.end()) {
                return {ump[need], i};
            }

            ump[nums[i]] = i;
        }
        return ansvec;
    }
};
// @lc code=end

int main(){
    return 0;
}
