class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
       int n = vals.size();
        vector<vector<int>> g(n);
        for(auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            int tt = vals[i];   
            for(int u : g[i]) {
                pq.push(vals[u]);              
                if(pq.size() > k) pq.pop(); 
            }
  
            while(!pq.empty()){ 
                if(pq.top() > 0) tt += pq.top(); 
                pq.pop(); 
            } 
            ans = max(tt, ans);
        }
        
        return  ans;
        
    }
};