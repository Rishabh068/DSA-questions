class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int j=0,i=0;
        int prod=1;
        if(k==0)
            return 0;
        while(j<nums.size()&&i<=j){
            prod=prod*nums[j];
            if(prod>=k){
                while(prod>=k&&i<=j){
                    prod=prod/nums[i];
                    i++;
                }
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
        
    }
};