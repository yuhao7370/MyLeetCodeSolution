#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for(int i = 0; i < strs.size(); ++i){
            string key = strs[i];
            sort(key.begin(), key.end());
            dict[key].push_back(strs[i]);
        }

        vector<vector<string>> ansvec;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            ansvec.push_back(it->second);
        }
        return ansvec;
    }
};
// @lc code=end

