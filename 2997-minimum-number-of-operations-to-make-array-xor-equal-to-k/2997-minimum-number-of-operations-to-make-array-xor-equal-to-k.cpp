class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=x xor nums[i];
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if((x&1<<i)==(k&1<<i))
                ans++;
        }
        return 32-ans;
        
    }
};