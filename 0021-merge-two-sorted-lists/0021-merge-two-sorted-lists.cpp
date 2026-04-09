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
        ListNode* temp1 = list1 , *temp2 = list2;
        if(temp1 == NULL)return temp2;
        else if(temp2 == NULL)return temp1;
        if(temp1->val >= temp2->val){
            temp2->next = mergeTwoLists(temp1 , temp2->next);
        }else{
            temp1->next = mergeTwoLists(temp1->next , temp2);
        }
    if(list1->val >= list2->val)return list2;
        return list1;
    }
};