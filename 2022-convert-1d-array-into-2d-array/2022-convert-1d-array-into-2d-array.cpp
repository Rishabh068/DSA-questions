class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>vec(m,vector<int>(n,-1));
        int k=0;
        if(m*n!=original.size())
            return {};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vec[i][j]=original[k++];
            }
        }
        return vec;
        
    }
};