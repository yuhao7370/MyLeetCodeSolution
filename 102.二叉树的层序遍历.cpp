#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans_vec;
        
        if(root != nullptr)
            q.push({root, 0});

        while (!q.empty())
        {
            TreeNode* cur;
            int depth;

            cur = q.front().first;
            depth = q.front().second;
            
            if(ans_vec.size()<=depth){
                ans_vec.push_back({});
            }

            ans_vec[depth].push_back(cur->val);

            if(cur->left!=nullptr)
                q.push({cur->left, depth+1});
            if(cur->right!=nullptr)
                q.push({cur->right, depth+1});

            q.pop();
        }
        
        return ans_vec;
    }
};
// @lc code=end

