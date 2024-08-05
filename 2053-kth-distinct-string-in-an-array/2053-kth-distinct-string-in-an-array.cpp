class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
     map<string,int>mp;
        int cnt=0;
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:arr){
            if(mp[it]==1){
                cnt++;
            
                if(cnt==k)
                    return it;
            }
        }
        return "";
        
    }
};