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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        temp=head;
        int div=count/k;
        int rem=count%k;
        vector<ListNode*>ans;
        while(k--){
            if(!temp){
                ans.push_back(nullptr);
                continue;
            }
            ListNode* prev=nullptr;
            for(int i=0;i<div;i++){
                prev=temp;
                temp=temp->next;
            }
            if(rem>0){
                prev=temp;
                temp=temp->next;
                rem--;
            }
            prev->next=nullptr;
            ans.push_back(head);
            head=temp;
        }
       
        return ans;
        
    }
};