class Solution {
public:
   vector<int>getnsr(vector<int>& arr,int n){
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) 
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
    vector<int>getnsl(vector<int>& arr,int n){
       vector<int> result(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) 
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        
        return result;
    }
   int largestRectangleArea(vector<int>& arr) {
        vector<int>NSL=getnsl(arr,arr.size());
        vector<int>NSR=getnsr(arr,arr.size());
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            int length=NSR[i]-NSL[i]-1;
            ans=max(ans,length*arr[i]);
        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>matrix1(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                    matrix1[i][j]=1;
                else
                    matrix1[i][j]=0;
            }
        }
        for(int i=1;i<matrix1.size();i++){
            for(int j=0;j<matrix1[0].size();j++){
                if(matrix1[i][j]==1)
                matrix1[i][j]+=matrix1[i-1][j];
                
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<matrix1.size();i++){
            ans=max(ans,largestRectangleArea(matrix1[i]));
        }
        return ans;
        
    }
};