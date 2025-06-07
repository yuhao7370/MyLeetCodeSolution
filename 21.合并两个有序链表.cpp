/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1;
        ListNode *p2;
        ListNode *head;
        ListNode *now;

        if (!list1) return list2;
        if (!list2) return list1;

        if(list1->val < list2 -> val){
            head = list1;
            p2 = list2;
            p1 = list1->next;
        } else{
            head = list2;
            p1 = list1;
            p2 = list2->next;
        }
        now = head;

        while(p1 && p2){
            if(p1 -> val < p2 ->val){
                ListNode* tmp = new ListNode(p1 -> val);
                now->next = tmp;
                now = tmp;
                p1 = p1->next;
            } else{
                ListNode* tmp = new ListNode(p2 -> val);
                now->next = tmp;
                now = tmp;
                p2 = p2->next;
            }
        }

        if(!p1){
            now->next = p2;
        } else{
            now->next = p1;
        }
        
        return head;
    }
};
// @lc code=end

