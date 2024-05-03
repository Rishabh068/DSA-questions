class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int>mp;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
        
         if(mp.find(-1*nums[i])!=mp.end())
             ans=max(ans,abs(nums[i]));
            
            mp[nums[i]]++;
        }
        return ans;
        
    }
};