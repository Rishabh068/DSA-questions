class Solution {
public:
    int appendCharacters(string s, string t) {
         int ns=s.size(), nt=t.size(), i=0, j=0;
        for(i=0; i<ns; i++){
            if(s[i]==t[j]) j++;
        }
        return nt-j;
    }
};