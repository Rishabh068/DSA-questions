class Solution {
public:
    vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
    bool check(int mid,vector<vector<int>>& dis)
    {
        queue<pair<int,int>> q;
        int m=dis.size();
        int n=dis[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        q.push({0,0});
        if(dis[0][0]<mid)
            return 0;
        vis[0][0]=1;
        while(q.size()>0)
        {
            auto p=q.front();
            q.pop();
            for(auto t: dirs)
            {
                int x=p.first+t.first;
                int y=p.second+t.second;
                if(x>=0 && y>=0 && x<m && y<n && dis[x][y]>=mid && vis[x][y]==0)
                {
                    // dis[x][y]=dis[p.first][p.second]+1;
                    q.push({x,y});
                    vis[x][y]=1;
                }
            }
        }
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return vis[m-1][n-1];
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        while(q.size()>0)
        {
            auto p=q.front();
            q.pop();
            for(auto t: dirs)
            {
                int x=p.first+t.first;
                int y=p.second+t.second;
                if(x>=0 && y>=0 && x<m && y<n && dis[x][y]>dis[p.first][p.second]+1)
                {
                    dis[x][y]=dis[p.first][p.second]+1;
                    q.push({x,y});
                }
            }
               
        }
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        int l=0,r=1e9;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,dis))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};