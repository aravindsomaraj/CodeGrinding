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
        
        ListNode *a = new ListNode(0);
        ListNode *curr = a;
        
        int carry = 0;
        
        while(l1!=NULL || l2!=NULL || carry==1)
        {
            int sum = 0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            
            sum+=carry;        //adding l1,l2, and carry at that position and evaluating carry and proper digit
            carry=sum/10;
            sum = sum%10;
            
            
            ListNode *l3 = new ListNode(sum);
            curr->next = l3;
            curr=curr->next;
        }
        return a->next;
        
    }
};