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
        int carry=0;

        ListNode *dummy=new ListNode(-1);
        ListNode *start=dummy;
        while(l1 && l2){
            int sum=l1->val+l2->val+carry;
            ListNode *node=new ListNode(sum%10);
            dummy->next=node;
            dummy=node;
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1){
            int sum=l1->val+carry;
             ListNode *node=new ListNode(sum%10);
            dummy->next=node;
            dummy=node;
            carry=sum/10;
            l1=l1->next;
        }

        while(l2){
             int sum=l2->val+carry;
             ListNode *node=new ListNode(sum%10);
            dummy->next=node;
            dummy=node;
            carry=sum/10;
            l2=l2->next;
        }

        if (carry){
            ListNode *node=new ListNode(carry);
            dummy->next=node;
        }
        return start->next;
    }
};