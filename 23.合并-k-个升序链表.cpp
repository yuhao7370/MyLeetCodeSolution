#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct cmp
{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b-> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> listq;

        for (int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != nullptr)
                listq.push(lists[i]);
        }

        ListNode dummy;
        ListNode *last;
        last = &dummy;

        while(!listq.empty()){
            ListNode *curtop;
            curtop = listq.top();

            last->next = curtop;
            last = curtop;

            listq.pop();

            if(curtop->next!=nullptr)
                listq.push(curtop->next);
        }
        return dummy.next;
    }
};
// @lc code=end

