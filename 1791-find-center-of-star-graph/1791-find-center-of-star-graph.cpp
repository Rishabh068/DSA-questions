class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+2;
        vector<int>indeg(n,0);
        for(auto it:edges){
            indeg[it[0]]++;
            indeg[it[1]]++;
        }
        int ans=0,maxindeg=INT_MIN;
        for(int i=0;i<n;i++){
            if(indeg[i]>maxindeg){
                maxindeg=indeg[i];
                ans=i;
            }
        }
        return ans;
        
    }
};