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
    int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head||head->next==nullptr)
            return head;
        ListNode* aage=head->next;
        ListNode* peeche=head;
        while(aage){
            int x=gcd(aage->val,peeche->val);
            ListNode* temp=new ListNode(x);
            temp->next=aage;
            peeche->next=temp;
            peeche=aage;
            aage=aage->next;
        }
        return head;
        
    }
};