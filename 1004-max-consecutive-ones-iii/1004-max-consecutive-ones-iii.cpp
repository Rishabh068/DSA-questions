class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,count=0,ans=0,temp=0;
        while(j<nums.size()&&i<=j){
            if(nums[j]==1){
                temp=j-i+1;;
                ans=max(temp,ans);
            }
            else if(nums[j]==0&&count<k){
                temp=j-i+1;
                count++;
                ans=max(temp,ans);
            }
            else if(nums[j]==0&&count==k){
                while(nums[i]==1){
                    i++;
                }
                i++;
            }
            j++;
        }
        return ans;
        
    }
};