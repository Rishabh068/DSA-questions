class Solution {
public:
    int minAddToMakeValid(string s) {
    stack<char>st;
        int extra=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    extra++;
                }
            }
        }
        return st.size()+extra;
        
    }
};