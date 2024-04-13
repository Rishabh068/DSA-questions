class Solution {
public:
     vector<int>getnsr(vector<int>& arr,int n){
        vector<int> result(n);
        stack<int> st;
        
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //non-strictly less
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
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
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
};