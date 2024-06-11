class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        vector<int>ans;
        for(auto it:arr1){
            mp[it]++;
        }
        for(int j=0;j<arr2.size();j++){
            int cnt=mp[arr2[j]];
            while(cnt--){
                ans.push_back(arr2[j]);
                mp[arr2[j]]--;
            }
        }
        for(auto it:mp){
            if(it.second>0){
                int cnt=it.second;
                while(cnt--){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
        
    }
};