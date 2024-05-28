class Solution {
public:
    int specialArray(vector<int>& nums) {
      int l=0,r=1000;
       int ans=-1;
       while(l<=r)
       {
           int mid=(l+r)/2;
           int cnt=0;
           for(auto x: nums)
               cnt+=(x>=mid);
           if(cnt==mid)
               return mid;
           else if(cnt>mid)
               l=mid+1;
           else
               r=mid-1;
       }
        return -1;
        
    }
};