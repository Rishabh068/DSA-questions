class Solution {
public:
    void helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&temp,int idx){
        if(target==0)
            ans.push_back(temp);
        if(target<0)
            return;
        if(idx==candidates.size())
            return;
        
        // helper(candidates,target,ans,temp,idx+1);
        for(int i=idx;i<candidates.size();i++){
           if(i==idx){
               temp.push_back(candidates[i]);
               helper(candidates,target-candidates[i],ans,temp,i+1);
               temp.pop_back();
               
           } else{
               if(i>idx && candidates[i]!=candidates[i-1]){
                   temp.push_back(candidates[i]);
                   helper(candidates,target-candidates[i],ans,temp,i+1);
                   temp.pop_back();
               }
               
           }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper(candidates,target,ans,temp,0);
        return ans;
    }
};