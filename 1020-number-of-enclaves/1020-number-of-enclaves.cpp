class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& board,vector<vector<int>>& visited,int n,int m){
        visited[i][j]=1;
         vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        for(auto[dx,dy]:dirs){
            int x=i+dx;
            int y=j+dy;
            if(x>=0&&y>=0&&x<n&&y<m&&!visited[x][y]&&board[x][y]==1){
                dfs(x,y,board,visited,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int ans=0;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
           if(board[i][0]==1)
               dfs(i,0,board,visited,n,m);
       }
        for(int j=0;j<m;j++){
           if(board[n-1][j]==1)
               dfs(n-1,j,board,visited,n,m);
       }
        for(int i=n-1;i>=0;i--){
           if(board[i][m-1]==1)
               dfs(i,m-1,board,visited,n,m);
       }
        for(int j=m-1;j>=0;j--){
           if(board[0][j]==1)
               dfs(0,j,board,visited,n,m);
       }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1&&!visited[i][j])
                    ans++;
            }
        }
        return ans;
        
    }
};