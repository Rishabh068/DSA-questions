class Solution {
public:
    bool helper(string &s1,string &s2,map<char,int>&m1,map<char,int>&m2){
        for(auto it:s1){
            if(m2.find(it)==m2.end()||m2[it]!=m1[it])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        map<char,int>m1;
        map<char,int>m2;
        for(auto it:s1){
            m1[it]++;
        }
        int i=0,j=0;
        while(j<s2.length()){
            m2[s2[j]]++;
        if(j-i+1>s1.length()){
            m2[s2[i]]--;
            i++;
        }
            if(j-i+1==s1.length()){
            bool ans=helper(s1,s2,m1,m2);
            if(ans)
                return true;
        }
        j++;
            
        }
        return false;
        
        
    }
};