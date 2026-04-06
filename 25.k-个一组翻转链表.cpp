struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, ListNode* end, ListNode* link){
        ListNode* prev;
        ListNode* cur;
        ListNode* next;
        ListNode* end_node;
        end_node = end->next;

        prev = link;
        cur = head;
        while(cur != end_node){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return end;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1){
            return head;
        }

        ListNode* start;
        ListNode* end;
        ListNode* cur;
        ListNode* last;
        ListNode* dummy;
        dummy = new ListNode();
        dummy->next = head;
        last = dummy;

        cur = head;
        for(int i = 1; cur != nullptr; ++i){
            if(i % k == 1){
                start = cur;
                cur = cur->next;
            } else if(i % k == 0){
                end = cur;
                cur = cur->next;
                last->next = reverseBetween(start, end, end->next);
                last = start;
            } else{
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
// @lc code=end

