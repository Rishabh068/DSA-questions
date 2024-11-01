class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int i=0;
        while(i<s.length()){
            if(i+2<s.length()&&s[i]==s[i+1]&&s[i]==s[i+2]){
                //skip
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
        
    }
};