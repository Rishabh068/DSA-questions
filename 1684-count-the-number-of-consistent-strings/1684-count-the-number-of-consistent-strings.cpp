class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>st;
        for(auto it:allowed){
            st.insert(it);
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            bool flag=true;
            for(auto it:words[i]){
                if(st.find(it)==st.end()){
                    flag=false;
                    break;
                }
                
            }
            if(flag)
                    ans++;
        }
        return ans;
        
    }
};