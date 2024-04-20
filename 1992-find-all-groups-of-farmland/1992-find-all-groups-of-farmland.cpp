class Solution {
public:
    static bool comp(pair<int,int>&x,pair<int,int>&y){
        if(x.first<y.first)
            return true;
        if(x.first==y.first&&x.second<y.second)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>&land,int i,int j,vector<pair<int,int>>&coordinates,vector<vector<int>>&visited){
        if(i==land.size()||j==land[0].size()||i<0||j<0||land[i][j]==0||visited[i][j]==1)
            return;
        coordinates.push_back({i,j});
        visited[i][j]=1;
        dfs(land,i+1,j,coordinates,visited);
        dfs(land,i-1,j,coordinates,visited);
        dfs(land,i,j+1,coordinates,visited);
        dfs(land,i,j-1,coordinates,visited);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        vector<pair<int,int>>coordinates;
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
            if(land[i][j]==1&&visited[i][j]!=1){
                cout<<i<<j<<endl;
                dfs(land,i,j,coordinates,visited);
               sort(coordinates.begin(),coordinates.end(),comp);
                vector<int>temp;
                auto x=coordinates[0];
                auto y=coordinates[coordinates.size()-1];
                temp.push_back(x.first);
                temp.push_back(x.second);
                temp.push_back(y.first);
                temp.push_back(y.second);
                ans.push_back(temp);
                temp.clear();
                coordinates.clear();
                  
                
            }
                
            }
        }
        return ans;
        
    }
};