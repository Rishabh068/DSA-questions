class Solution {
public:
void helper(vector<int>nums,vector<vector<int>>&result,vector<int>&op){
    if(nums.size()==0){
        result.push_back(op);
        return;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    
    op2.push_back(nums[0]);
    nums.erase(nums.begin()+0);
    helper(nums,result,op1);
     helper(nums,result,op2);
     return;
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
        vector<vector<int>>result;
        helper(nums,result,op);
        return result;
        
    }
};