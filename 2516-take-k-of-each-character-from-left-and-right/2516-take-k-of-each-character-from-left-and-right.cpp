class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0,b=0,c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a')
                a++;
            else if(s[i]=='b')
                b++;
            else
                c++;
        }
         if(a<k||b<k||c<k)
            return -1;
        int ta=a-k,tb=b-k,tc=c-k;
       
        map<char,int>mp;
        
        int ans=INT_MIN;
        int i=0,j=0;
        while(j<s.length()){
            mp[s[j]]++;
           while(mp['a']>ta||mp['b']>tb||mp['c']>tc){
               mp[s[i]]--;
               i++;
           }
            if(mp[a]<=ta&&mp[b]<=tb&&mp[c]<=tc){
                ans=max(ans,j-i+1);
                cout<<i<<" "<<j<<endl;
            }
            j++;
            
        }
        return s.length()-ans;
        
        
    }
};