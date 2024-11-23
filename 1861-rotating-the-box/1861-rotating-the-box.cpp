class Solution {
public:
    void transpose(vector<vector<char>>& A,vector<vector<char>>& B,int n,int m){
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               B[i][j]=A[j][i];
               
           }
       }
        for(int i=0;i<m;i++){
            reverse(B[i].begin(),B[i].end());
        }
          for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               cout<<B[i][j]<<" ";
               
           }
              cout<<endl;
       }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
      int m=box[0].size();
        int n=box.size();
        vector<vector<char>>newbox(m,vector<char>(n,'.'));
      transpose(box,newbox,n,m);
        int last;
        for(int j=0;j<n;j++){
           last=m;
            for(int i=m-1;i>=0;i--){
                if(newbox[i][j]=='#'){
                    newbox[last-1][j]='#';
                    if(last-1!=i)
                    newbox[i][j]='.';
                    last=last-1;
                }
                if(newbox[i][j]=='*')
                    last=i;
            }
        }
        return newbox;
        
        
    }
};