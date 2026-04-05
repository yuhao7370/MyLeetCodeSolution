struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *safenext_next(ListNode *cur){
        if(cur == nullptr || cur->next == nullptr){
            return nullptr;
        }
        else{
            return cur->next->next;
        }
    }

    ListNode *safenext(ListNode *cur){
        return cur->next;
    }

    bool hasCycle(ListNode *head) {
        ListNode *fast;
        ListNode *slow;
        if(head == nullptr){
            return false;
        }
        if(head->next == nullptr){
            return false;
        } 
        if(head->next == head){
            return true;
        }

        slow = safenext(head);
        fast = safenext_next(head);
        while(true){
            if(fast == nullptr){
                return false;
            }
            if(slow == fast){
                return true;
            } 
            slow = safenext(slow);
            fast = safenext_next(fast);
        }
    }
};
// @lc code=end

