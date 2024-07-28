class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>matrix(26,vector<int>(26,1e9));
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j)
                matrix[i][j]=0;
            }
        }
        for(int i=0;i<original.size();i++){
            matrix[original[i]-'a'][changed[i]-'a']=min(matrix[original[i]-'a'][changed[i]-'a'],cost[i]);
        }
        for (int k = 0; k < 26; k++) {
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}
        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]!=target[i]){
                if(matrix[source[i]-'a'][target[i]-'a']>=1e9)
                    return -1;
                else
                ans+=matrix[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};