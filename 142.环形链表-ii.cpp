struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
ListNode *safe_next_next(ListNode *cur){
    if(cur == nullptr || cur->next == nullptr){
        return nullptr;
    } else{
        return cur->next->next;
    }
}

ListNode *safe_next(ListNode *cur){
    if(cur == nullptr){
        return nullptr;
    } else{
        return cur->next;
    }
}

ListNode *detectCycle(ListNode *head) {
        ListNode* fast;
        ListNode* slow;
        slow = safe_next(head);
        fast = safe_next_next(head);

        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        ListNode* meet;

        while(true){
            if(slow == fast){
                meet = slow;
                break;
            }
            if(fast == nullptr){
                return nullptr;
            }

            slow = safe_next(slow);
            fast = safe_next_next(fast);
        }

        slow = head;
        fast = meet;

        while(true){
            if(slow == fast){
                return slow;
            }
            slow = safe_next(slow);
            fast = safe_next(fast);
        }
    }
};
// @lc code=end

