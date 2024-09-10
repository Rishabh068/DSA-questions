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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        int dir=0;
        int up=0,left=0,down=m-1,right=n-1;
        while(head){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    matrix[up][i]=head->val;
                    head=head->next;
                    if(!head)
                        break;
                }
                up++;
                dir=(dir+1)%4;
            }
             else if(dir==1){
                for(int i=up;i<=down;i++){
                    matrix[i][right]=head->val;
                    head=head->next;
                    if(!head)
                        break;
                }
                 right--;
                dir=(dir+1)%4;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    matrix[down][i]=head->val;
                    head=head->next;
                    if(!head)
                        break;
                }
                 down--;
                dir=(dir+1)%4;
            }
             else{
                for(int i=down;i>=up;i--){
                    matrix[i][left]=head->val;
                    head=head->next;
                    if(!head)
                        break;
                }
                 left++;
                dir=(dir+1)%4;
            }
        }
        return matrix;
        
    }
};