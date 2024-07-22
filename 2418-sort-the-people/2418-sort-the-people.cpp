class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>vec;
        for(int i=0;i<names.size();i++){
            vec.push_back({heights[i],names[i]});
        }
        sort(vec.begin(),vec.end());
        vector<string>ans;
        for(auto it:vec){
            ans.push_back(it.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};