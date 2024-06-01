class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum=0;
        for(int i=0;i<nums.size();i++){
            xorsum^=nums[i];   
        }
        int bit=0;
        for(int i=0;i<32;i++){
            if(xorsum&(1<<i)){
                bit=i;
                break;
            }
        }
        vector<int>t1;
        vector<int>t2;
        for(auto it:nums){
            if(it&(1<<bit))
                t1.push_back(it);
            else
                t2.push_back(it);
        }
        int t1sum=0,t2sum=0;
        for(auto it:t1){
            t1sum=t1sum^it;
        }
         for(auto it:t2){
            t2sum=t2sum^it;
        }
        vector<int>ans;
        ans.push_back(t1sum);
         ans.push_back(t2sum);
        return ans;
        
    }
};