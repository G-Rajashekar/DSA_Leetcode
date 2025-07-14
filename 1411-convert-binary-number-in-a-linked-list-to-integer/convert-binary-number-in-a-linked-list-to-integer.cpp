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
    int getDecimalValue(ListNode* head) {
        int n=0;
        ListNode *temp=head;

        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }

        n--;
        temp=head;
        int dec=0;

        while(temp){
            if (temp->val==1)
                 dec+=(int)pow(2,n);
            n--;
            temp=temp->next;
        }
        return dec;
    }
};