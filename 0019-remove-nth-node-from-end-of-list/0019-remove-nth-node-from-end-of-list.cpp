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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode  *curr = head;
        // if(!head  ||  !head->next)return NULL;

        int N = 0;
        while(curr){
            curr = curr->next;
            N++;
        } 
        int pos = N-n , i = 1;
        curr = head;
        if(pos == 0){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        while(curr && i < pos){
            curr = curr->next;
            i++;
        }
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
};