class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long ans=0;
        while(k--){
            long long x=pq.top();
            pq.pop();
            ans+=x;
            pq.push((x+2)/3);
        }
        return ans;
        
    }
};