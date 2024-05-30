class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int>pref(begin(arr),end(arr));
        pref.insert(pref.begin(),0);
        int n=pref.size();
        for(int i=1;i<n;i++){
           pref[i]^=pref[i-1];
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                if(pref[k]==pref[i]){
                    ans+=k-i-1;
                }
            }
        }
        return ans;
        
    }
};