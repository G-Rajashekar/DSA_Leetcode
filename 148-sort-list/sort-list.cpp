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
    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;

        ListNode *slow=head;
        ListNode *fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=nullptr;
        return merge(sortList(head),sortList(fast));
    }

    ListNode *merge(ListNode *l1,ListNode *l2){
        ListNode *dummy=new ListNode(-1);
        ListNode *cur=dummy;

        while(l1 && l2){
            if (l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }

        if (l1) cur->next=l1;
        else cur->next=l2;
        return dummy->next;
    }
};