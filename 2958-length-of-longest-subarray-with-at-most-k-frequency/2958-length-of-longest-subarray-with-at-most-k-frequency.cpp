class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MIN;
        int j=0,i=0;
        map<int,int>mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                while(mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
        
    }
};