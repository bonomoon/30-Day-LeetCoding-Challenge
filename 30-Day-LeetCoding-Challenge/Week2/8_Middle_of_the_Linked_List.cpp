/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// fast and slow pointers solution
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        struct ListNode* fastPtr = head;
        struct ListNode* slowPtr = head;
        
        while(fastPtr != NULL && fastPtr->next != NULL) {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        
        return slowPtr;
    }
};

// improved 1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* mid = head;
        
        while(head != NULL && head->next != NULL) {
            head = head->next->next;
            mid = mid->next;
        }
        return mid;
    }
};

// improved 2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        for(ListNode* listPtr = head; listPtr != NULL && listPtr->next != NULL; listPtr = listPtr->next->next, head = head->next);
        return head;
    }
};