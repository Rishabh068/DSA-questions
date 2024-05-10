class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>>fractions;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                double fraction=(double)arr[i]/(double)arr[j];
                  pair<int,int>p={i,j};
                fractions.push_back({fraction,p});
            }
        }
        sort(fractions.begin(),fractions.end());
        
        vector<int>ans;
        ans.push_back(arr[fractions[k-1].second.first]);
           ans.push_back(arr[fractions[k-1].second.second]);
return ans;        
    }
};