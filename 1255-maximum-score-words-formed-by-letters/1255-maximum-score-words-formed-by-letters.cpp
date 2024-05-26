class Solution {
public:
    map<char,int>mp;
    int helper(vector<int>&score,int idx,vector<string>& words){
        if(idx==words.size()){
            return 0;
        }
        int option1=0,option2=0;
        option1=helper(score,idx+1,words);
        
        string str=words[idx];
        int i=0,sum=0;
        bool flag=true;
        for( i=0;i<str.length();i++){
            if(mp.find(str[i])!=mp.end()&&mp[str[i]]>=1){
                mp[str[i]]--;
                sum+=score[str[i]-'a'];
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag==true){
            option2=sum+helper(score,idx+1,words);
        }
        
            // cout<<idx<<" "<<i<<endl;
            for(int j=0;j<i;j++){
                mp[str[j]]++;
            }
        return max(option1,option2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        mp.clear();
        for(int i=0;i<letters.size();i++){
            mp[letters[i]]++;
        }
        // for(auto t: mp)
        //     cout<<t.first<<" "<<t.second<<endl;
        int ans=helper(score,0,words);
        return ans;
        
    }
};