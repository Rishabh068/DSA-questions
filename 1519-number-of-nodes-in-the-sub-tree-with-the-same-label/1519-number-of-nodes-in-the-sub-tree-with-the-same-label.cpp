class Solution {
public:
    void helper(int n,string& labels,unordered_map<int,vector<int>>&adj,int parent,int node,vector<int>&chars,vector<int>&ans){
        int before=chars[labels[node]-'a'];
         chars[labels[node]-'a']++;
        for(auto it:adj[node]){
            if(it!=parent){
                helper(n,labels,adj,node,it,chars,ans);
            }  
        }
        int after=chars[labels[node]-'a'];
                         
       
        ans[node]=after-before;
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>chars(26,0);
        vector<int>ans(n,0);
        helper(n,labels,adj,-1,0,chars,ans);
        return ans;
        
    }
};