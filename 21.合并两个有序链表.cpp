struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        } else if(list2 == nullptr){
            return list1;
        }

        ListNode* cur1;
        ListNode* cur2;
        ListNode* last;
        ListNode* dummyhead;
        dummyhead = new ListNode();
        last = dummyhead;

        cur1 = list1;
        cur2 = list2;

        while(true){
            if(cur1 == nullptr){
                last->next = cur2;
                break;
            } else if(cur2 == nullptr){
                last->next = cur1;
                break;
            }

            if(cur1->val < cur2->val){
                last->next = cur1;
                last = cur1;
                cur1 = cur1->next;
            } else{
                last->next = cur2;
                last = cur2;
                cur2 = cur2->next;
            }
        }

        return dummyhead->next;
    }
};
// @lc code=end

