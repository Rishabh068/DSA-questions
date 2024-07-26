class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> matrix(n,vector<int>(n,INT_MAX)); 

        for(int i=0;i<n;i++){
            matrix[i][i]=0;   
        }

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt =edges[i][2];
            matrix[u][v]=wt; 
            matrix[v][u]=wt;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX) continue;
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }

        int temp=n,res=0; 

        for(int i=0;i<n;i++){
            int curr = 0;
            for(int j=0;j<n;j++){
                if(distanceThreshold>=matrix[i][j]) curr++; 
            }
            if(temp>=curr){
                temp=curr; 
                res=i; 
            }
        }

        return res;

    }
};