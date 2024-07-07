class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        unordered_map<string, int> mp, vis;
        for(auto x: wordList) mp[x] = 1;
        if(!mp[endWord]) return 0;
        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = 1;
        int ans = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                string u = q.front();
                q.pop();
                if(u == endWord) {
                    return ans + 1;
                }
                for(int i=0; i<n; i++) {
                    for(char c='a'; c<='z'; c++) {
                        string v = u;
                        v[i] = c;
                        if(!vis[v] and mp[v]) {
                            q.push(v);
                            vis[v] = 1;
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};