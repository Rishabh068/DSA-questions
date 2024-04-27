class Solution {
public:
    int helper(vector<int>& nums, int target,int idx){
        if(idx==nums.size()){
        if(target==0)
            return 1;
        else
            return 0;
        }
        int option1=helper(nums,target+nums[idx],idx+1);
        int option2=helper(nums,target-nums[idx],idx+1);
            return option1+option2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int op1=helper(nums,target,0);
        
        return op1;
        
    }
};