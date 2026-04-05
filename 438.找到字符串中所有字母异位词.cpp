#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    bool check_equal(vector<int>& a, vector<int> &b){
        if(a.size() != b.size()){
            return false;
        }

        for(int i = 0; i < a.size(); ++i){
            if(a[i]!=b[i]){
                return false;
            }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> pcount(27,0);
        vector<int> s_sub(27,0);
        vector<int> ansvec;
        int slen=s.length(), plen=p.length();

        if(slen < plen) return {};

        for(int i = 0; i < p.length(); ++i){
            pcount[p[i]-'a']++;
        }

        int cur = 0;
        for(int i = 0; i < p.length(); ++i){
            s_sub[s[i]-'a']++;
        }

        while(cur <= slen - plen){
            if(check_equal(s_sub, pcount)){
                ansvec.push_back(cur);
            }

            if(cur == slen - plen){
                break;
            }

            s_sub[s[cur] - 'a']--;
            s_sub[s[cur + plen] - 'a']++;
            ++cur;
        }
        
        return ansvec;
    }
};
// @lc code=end

