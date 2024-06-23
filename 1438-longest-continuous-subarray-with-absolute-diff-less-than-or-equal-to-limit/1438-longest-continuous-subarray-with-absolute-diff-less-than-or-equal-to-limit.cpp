class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        int j=0,i=0;
        multiset<int>st;
        while(j<nums.size()){
            st.insert(nums[j]);
            int minele=*(st.begin());
            int maxele=*(st.rbegin());
            if(abs(maxele-minele)>limit){
                while(abs(maxele-minele)>limit&&i<=j){
                    st.erase(st.find(nums[i]));
                    i++;
                      minele=*(st.begin());
                      maxele=*(st.rbegin());
                }
            }
            ans=max(ans,j-i+1);
            j++;
           
        }
        return ans;
    }
};