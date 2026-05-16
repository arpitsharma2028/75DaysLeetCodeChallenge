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
    // brute force solution => O(N) , O(N)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode * , bool>vis;
        ListNode* temp = headA;
        while(temp){
            vis[temp] = true;
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            if(vis.find(temp) != vis.end())return temp;
            temp = temp->next;
        }
        return NULL;
    }
};