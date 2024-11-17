class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size()+1, 0);
        prefix[1] = nums[0];
        
        for(int i = 2 ; i <= nums.size() ; i++)
        {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        deque<int> dq;
        dq.push_front(0);
        
        int i = 0 ,  j =0;
        int count = nums.size()+1;
        for(j = 1 ; j <= nums.size() ; j++)
        {
            while(dq.size() && prefix[j] - prefix[dq.front()] >= k)
                count = min(count, j-dq.front()), dq.pop_front();
            
            while(dq.size() && prefix[dq.back()] >= prefix[j])
                dq.pop_back();
            
            dq.push_back(j);
        }
        return count == nums.size()+1 ? -1 : count;
    }
};