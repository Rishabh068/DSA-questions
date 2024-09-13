class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>pref(arr.size(),-1);
        pref[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            pref[i]=arr[i]^pref[i-1];
        }
        vector<int>ans;
        for(auto it:queries){
            int start=it[0];
            int end=it[1];
            if(start==0){
                ans.push_back(pref[end]);
            }
            else{
                ans.push_back(pref[end]^pref[start-1]);
            }
        }
        return ans;
        
        
    }
};