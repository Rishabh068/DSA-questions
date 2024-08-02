class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalones=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                totalones++;
        }
        int i=0,j=0,currones=0,ans=INT_MAX;
        while(j<2*n){
            if(nums[j%n]==1)
                currones++;
            if(j-i+1>totalones){
               
              currones-=nums[i%n];
                i++;
            }
            ans=min(ans,totalones-currones);
            j++;
        }
        return ans;
        
    }
};