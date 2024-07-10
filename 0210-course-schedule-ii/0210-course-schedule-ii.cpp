class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        queue<int>q;
        
        vector<int>topo;
        
        vector<int>adj[numCourses];
        for(int i=0;i<n;i++){
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            adj[y].push_back(x);
        }
vector<int>indeg(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i])
                indeg[it]++;
            
        }
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int x=q.front();
            topo.push_back(x);
            q.pop();
            cnt++;
            for(auto it:adj[x]){
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        if(cnt==numCourses)
            return topo;
        else
            return {};
        
        
    }
};