class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>Lis;
        for(auto it:nums){
            if(Lis.size()==0){
                Lis.push_back(it);
            }
            else if(Lis[Lis.size()-1]<it){
                Lis.push_back(it);
            }
            else{
                int low=0,high=Lis.size()-1;
                int ans=-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(Lis[mid]>=it){
                        ans=mid;
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                if(ans!=-1)
                Lis[ans]=it;
            }
        }
        return Lis.size();
        
    }
};