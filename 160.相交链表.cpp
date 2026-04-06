struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena=0, lenb=0;
        ListNode *cur;
        cur = headA;
        while(cur != nullptr){
            ++lena;
            cur = cur->next;
        }
        cur = headB;
        while(cur != nullptr){
            ++lenb;
            cur = cur->next;
        }

        ListNode* acur= headA;
        ListNode* bcur= headB;

        if(lena>lenb){
            for(int i = 1; i <= lena-lenb; ++i){
                acur = acur->next;
            }
        } else{
            for(int i = 1; i <= lenb-lena; ++i){
                bcur = bcur->next;
            }
        }

        while(acur != nullptr){
            if(acur == bcur){
                return acur;
            }

            acur=acur->next;
            bcur=bcur->next;
        }

        return nullptr;
    }
};
// @lc code=end

