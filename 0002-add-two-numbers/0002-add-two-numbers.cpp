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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* L3  = new ListNode(0);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* temp3 = L3;
        int sum = 0 , carr = 0;

        while(temp1 != NULL || temp2 != NULL || carr != 0 ){
            int val1 =  temp1 != NULL ? temp1->val : 0 ;
            int val2 = temp2 != NULL ? temp2->val : 0 ;
            sum = val1 + val2 + carr ;
            carr = sum/10;
            int dig = sum %10 ;
            temp3->next = new ListNode(dig);
            temp3 = temp3->next ;
            if(temp1 != NULL)temp1 = temp1->next;
            if(temp2 != NULL)temp2 = temp2->next;
        }
         return L3->next ;
    }
};
