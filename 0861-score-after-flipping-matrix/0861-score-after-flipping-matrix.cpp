class Solution {
public:
    int helper(vector<int>&v){
        int sum=0;
        int exp=0,idx=v.size()-1;
        while(exp<=v.size()-1){
            sum=sum+v[idx]*pow(2,exp);
            cout<<sum<<" ";
            exp++;
            idx--;
        }
        cout<<sum<<endl;
        return sum;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j]=grid[i][j]^1;
                }
            }
        }
        
        for(int j=1;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==0)
                    cnt++;
            }
            if(cnt>n/2){
                for(int i=0;i<n;i++){
                grid[i][j]=grid[i][j]^1;
            }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=helper(grid[i]);
        }
        return ans;
        
    }
};