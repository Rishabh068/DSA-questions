class Solution {
public:
    int f(int i,vector<int>& nums,vector<int>& st,int k)
    {
        if(i==nums.size())
        {
            return st.size()>0;
        }
        int l=0,r=st.size()-1;
        bool found = false;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(st[mid]==nums[i]-k)
            {
                found=true;
                break;
            }
            else if(st[mid]>nums[i]-k)
                r=mid-1;
            else
                l=mid+1;
        }
        if(!found)
        {
            st.push_back(nums[i]);
            ans+=f(i+1,nums,st,k);
            st.pop_back();
        }
        ans+=f(i+1,nums,st,k);
        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) 
    {
        sort(begin(nums),end(nums));  
        vector<int> st;
        int ans=f(0,nums,st,k);
        return ans;
    }
};