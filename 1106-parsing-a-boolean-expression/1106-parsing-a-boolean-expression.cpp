class Solution {
public:
    bool solve(char ch,vector<char>vec){
        int tcount=0;
        int fcount=0;
        for(auto it:vec){
            if(it=='t')
                tcount++;
            if(it=='f')
                fcount++;
        }
        if(ch=='&'&&fcount>=1)
            return false;
        else if(ch=='|'&&tcount==0)
            return false;
        else if(ch=='!'&&vec[0]=='t')
            return false;
        return true;
        
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(int i=0;i<expression.length();i++){
            if(expression[i]==')'){
                vector<char>vec;
                while(st.top()!='('){
                    vec.push_back(st.top());
                    st.pop();
                    
                }
                st.pop();
                char eval=st.top();
                st.pop();
                bool ans=solve(eval,vec);
                if(ans==true)
                    st.push('t');
                else
                    st.push('f');
            }
            else{
                st.push(expression[i]);
            }
        }
        return st.top()=='t'?true:false;
        
    }
};