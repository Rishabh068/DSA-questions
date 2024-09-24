class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(auto it:arr1){
            while(st.find(it)==st.end()&&it>0){
                st.insert(it);
                it=it/10;
            }
        }
        int ans=0;
        for(auto it:arr2){
            while(st.find(it)==st.end()&&it>0){
                it=it/10;
            }
            if(it>0)
                ans=max(ans,static_cast<int>(log10(it)+1));
        }
        return ans;
    }
};