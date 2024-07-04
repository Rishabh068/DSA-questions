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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* front=head;
        ListNode* back=head->next;
        ListNode* dummy=new ListNode(0);
        ListNode* lastNode=dummy;
        int sum=0;
        while(back!=nullptr){
            while(back->val!=0){
                sum+=back->val;
                back=back->next;
            }
            ListNode* newnode=new ListNode(sum);
            lastNode->next=newnode;
            lastNode=newnode;
            sum=0;
            front=back;
            back=back->next;
        }
        return dummy->next;
    }
};