class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.length();i++){
            while(!st.empty()&&k>0&&st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(!st.empty()&&k>0){
            st.pop();
            k--;
        }
        if(st.empty())
            return "0";
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.length()==1)
            return ans;
        int len=ans.length();
        int i=0;
        if(ans[0]=='0'){
            cout<<true<<endl;
            while(ans[i]=='0'){
                i++;
            }
            ans=ans.substr(i,len-i);
        }
        if(ans=="")
            ans="0";
        return ans;
        
    }
};