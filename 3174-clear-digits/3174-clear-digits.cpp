class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        string ans;
        for(auto it:s){
            if(it>='0'&&it<='9'&&!st.empty()){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};