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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(head!=nullptr){
            while(head!=nullptr&&mp.find(head->val)!=mp.end()){
                head=head->next;
            }
            temp->next=head;
            temp=head;
            if(head)
            head=head->next;  
            
        }
        return dummy->next;
        
    }
};