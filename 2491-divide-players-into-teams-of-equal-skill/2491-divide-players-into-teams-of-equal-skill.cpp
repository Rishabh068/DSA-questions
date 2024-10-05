class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum=0;
        map<int,int>mp;
        for(int i=0;i<skill.size();i++){
            sum+=skill[i];
            mp[skill[i]]++;
        }
        if(skill.size()==2)
            return skill[0]*skill[1];
       int x=skill.size()/2;
        int skillpergroup=sum/x;
        sort(skill.begin(),skill.end());
        long long ans=0;
        for(int i=0,j=skill.size()-1;i<j;i++,j--){
            if(skill[i]+skill[j]==skillpergroup)
            ans+=skill[i]*skill[j];
            else
                return -1;
        }
        return ans;
        
        
    }
};