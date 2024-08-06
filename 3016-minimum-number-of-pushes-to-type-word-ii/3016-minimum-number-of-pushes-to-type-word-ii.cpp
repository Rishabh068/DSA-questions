class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        for(auto it:word){
            mp[it]++;
        }
        vector<pair<int,char>>vec;
        for(auto it:mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        int buttons=0,ans=0;
        for(int i=0;i<vec.size();i++){
            if(buttons>=0&&buttons<8){
                ans+=vec[i].first;
            }
            else if(buttons>=8&&buttons<16){
                ans+=2*vec[i].first;
            }
            else if(buttons>=16&&buttons<24){
                ans+=3*vec[i].first;
            }
            else{
                ans+=4*vec[i].first;
            }
            buttons++;
        }
        return ans;
    }
};