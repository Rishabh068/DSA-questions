class Solution {
public:
    int add(vector<int>& nums,int idx,vector<int>&bits){
        int curror=0;
        for(int i=0;i<32;i++){
            if(nums[idx]&(1<<i)){
                bits[i]++; 
            }
            if(bits[i]>0)
                 curror|=(1<<i);
        }
        return curror;
    }
    int remove(vector<int>& nums,int idx,vector<int>&bits){
         int curror=0;
        for(int i=0;i<32;i++){
            if(nums[idx]&(1<<i)){
                bits[i]--;
               if(bits[i]<0)
              bits[i]=0;
                
            }
            if(bits[i]!=0)
              curror|=(1<<i);   
        }
        return curror;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>bits(32,0);
        int j=0,i=0;
        int ans=INT_MAX;
        while(j<nums.size()){
            int curror=add(nums,j,bits);
            while(curror>=k&&i<=j){
                
                ans=min(ans,j-i+1);
                curror=remove(nums,i,bits);
               
                i++;
                
            }
            j++;
            
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};