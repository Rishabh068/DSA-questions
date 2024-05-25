class Solution {
public:
    void helper(string s,set<string>&st,int idx,string temp,vector<string>&ans){
   if(idx==s.length()){
       ans.push_back(temp);
       return;
   }
        string str="";
        for(int i=idx;i<s.length();i++){
            str+=s[i];
            if(st.find(str)!=st.end()){
                helper(s,st,i+1,temp==""?str:temp+" "+str,ans);
            }
            
        }
        
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string temp="";
        set<string>st;
        for(auto it:wordDict){
            st.insert(it);
        }
        helper(s,st,0,temp,ans);
        return ans;
        
    }
};