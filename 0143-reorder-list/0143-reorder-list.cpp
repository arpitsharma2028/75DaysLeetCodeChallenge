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
    ListNode*  reverse(ListNode* head){
        ListNode *prev = NULL , *next = NULL , *curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* fast = head , *slow = head , *prev = head;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev ->next = NULL;
        ListNode* RevHead = reverse(slow) , *FarwardHead = head;
        while (RevHead) {
            ListNode* next1 = FarwardHead->next;
            ListNode* next2 = RevHead->next;

            FarwardHead->next = RevHead;
            if(next1 == NULL) break;
            RevHead->next = next1;

            FarwardHead = next1;
            RevHead = next2;
        }
    }   
};