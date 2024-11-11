class Solution {
public:
        vector<int> SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
vector<int>primes;
    for (int p = 2; p <= n; p++){
        if (prime[p])
            primes.push_back(p);
    }
        return primes;
}
    int bs(vector<int>&nums,int idx,vector<int>&primes){
        int low=0,high=primes.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(primes[mid]<nums[idx]){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans==-1?-1:ans;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int>primes=SieveOfEratosthenes(1000);
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])
                continue;
            int last=bs(nums,i,primes);
            int start=0,ans=-1;
            while(start<=last){
                int mid=start+(last-start)/2;
                if(nums[i]-primes[mid]<nums[i+1]){
                    ans=mid;
                    last=mid-1;
                    
                }
                else{
                    start=mid+1;
                }
            }
            if(ans==-1)
                return false;
            else
                nums[i]-=primes[ans];
           
        }
        return true;
        
        
    }
};