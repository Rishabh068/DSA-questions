class Solution {
public:
    const int mod=1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<int>vec(n,1);
        for(int i=0;i<k;i++){
            for(int j=1;j<n;j++){
                vec[j]=(vec[j-1]%mod+vec[j]%mod)%mod;
            }
        }
        return vec[vec.size()-1];
    }
};