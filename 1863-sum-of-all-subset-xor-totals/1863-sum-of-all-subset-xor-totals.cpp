class Solution {
public:
    void helper(vector<int>& nums,int idx, vector<vector<int>>&vec,vector<int>v){
        if(idx==nums.size()){
            vec.push_back(v);
            return;
        }
        vector<int>v1=v;
        vector<int>v2=v;
        v1.push_back(nums[idx]);
        helper(nums,idx+1,vec,v1);
       
        helper(nums,idx+1,vec,v2);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        vector<vector<int>>vec;
        vector<int>v;
        helper(nums,0,vec,v);
       for(int i=0;i<vec.size();i++){
           int xorsum=0;
           for(int j=0;j<vec[i].size();j++){
               xorsum^=vec[i][j];
           }
           ans+=xorsum;
       }
        return ans;
        
    }
};