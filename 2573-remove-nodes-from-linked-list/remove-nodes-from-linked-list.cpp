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
    ListNode* removeNodes(ListNode* head) {
        reverse(head);

        ListNode *temp=head;

        while(temp && temp->next){
            if (temp->next->val<temp->val){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }

        }
        reverse(head);
        return head;
    }

    void reverse(ListNode *&head){

        ListNode *prev=nullptr;
        ListNode *cur=head;

        while(cur){
            ListNode *Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
        }
       head=prev;
    }
};