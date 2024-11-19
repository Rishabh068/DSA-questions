class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int i=0,j=0;
        long long ans=0;
        long long sum=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            sum+=nums[j];
            while(j-i+1>k){
                sum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            if(j-i+1==k&&mp.size()==k)
                ans=max(ans,sum);
            j++;
        }
        return ans==INT_MAX?0:ans;
        
    }
};