/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        nums3 = nums1;

        int p1=0, p2=0;

        while(p1 + p2 <= m + n - 1){
            if(p1>=m || p2>=n){
                if(p1>=m){
                    for (int i = p2; i < n; ++i){
                        nums1[p1+i]=nums2[i];
                    }
                } else if(p2>=n){
                    for (int i = p1; i < m; ++i){
                        nums1[p2+i]=nums3[i];
                    }
                }
                break;
            }

            if(nums3[p1] < nums2[p2]){
                nums1[p1+p2] = nums3[p1];
                ++p1;
            } else{
                nums1[p1+p2] = nums2[p2];
                ++p2;
            }
        }

        
    }
};
// @lc code=end

