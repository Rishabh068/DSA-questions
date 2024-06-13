class Solution {
public:
    int minimumChairs(string s) {
        int chairs=0;
        int curr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='E'){
                if(curr==0)
                    chairs++;
                if(curr!=0)
                    curr--;
            }
            else{
                curr++;
            }
        }
        return chairs;
        
    }
};