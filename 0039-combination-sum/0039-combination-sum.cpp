class Solution {
public:
    void helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&temp,int sum,int idx){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        
     if(sum>target||idx==candidates.size())
          return;
       
        if(sum+candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            helper(candidates,target,ans,temp,sum+candidates[idx],idx);
            temp.pop_back();
            helper(candidates,target,ans,temp,sum,idx+1);
            
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper(candidates,target,ans,temp,0,0);
        return ans;
        
    }
};