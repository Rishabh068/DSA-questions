class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
     int courses=0;
       vector<int>indeg(numCourses,0);
        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            cout<<i<<" ->"<<indeg[i]<<" ";
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
           int x= q.front();
            q.pop();
            courses++;
            for(auto it:adj[x]){
                indeg[it]--;
              if(indeg[it]==0)
                  q.push(it);
            }
        }
        if(courses==numCourses)
            return true;
        return false;
        
        
    }
};