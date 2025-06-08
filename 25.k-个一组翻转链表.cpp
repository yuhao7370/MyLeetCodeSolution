#include <iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseOne(ListNode* head, ListNode* tail){
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr!= tail){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(); // 😹
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        int cnt = 0;
        ListNode* lp;
        ListNode* rp;
        ListNode * lastTail;
        while (curr) {
            if (cnt == 0) {
                lastTail = curr;
            } else if (cnt == 1) {
                lp = curr;
            }

            ++cnt;
            curr = curr->next;

            if (cnt == k + 1) {
                rp = curr; // [lp, rp)
                ListNode* nextSegment = curr;
                ListNode* newHead = reverseOne(lp, rp);
                lastTail->next = newHead;
                lp->next = nextSegment;
                curr = lp;
                cnt = 0;
            }
        }

        return dummyHead->next;
    }
};
// @lc code=end

int main(){
    cout << "😹";
    return 0;
}

