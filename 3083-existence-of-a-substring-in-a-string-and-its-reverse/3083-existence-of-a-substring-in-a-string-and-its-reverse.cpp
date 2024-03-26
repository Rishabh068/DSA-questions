class Solution {
public:
    bool isSubstringPresent(string s) {
        set<string>st;
        for(int i=0;i<s.length()-1;i++){
            string str;
            str+=s[i];
            str+=s[i+1];
            st.insert(str);
            
        }
        reverse(s.begin(),s.end());
            for(int i=0;i<s.length()-1;i++){
            string str;
            str+=s[i];
            str+=s[i+1];
            if(st.find(str)!=st.end())
                return true;
            
        }
        return false;
        
        
    }
};