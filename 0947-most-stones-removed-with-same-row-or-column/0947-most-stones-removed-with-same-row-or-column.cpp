class DisjointSet{
        
public:
    vector<int>rank,parent;
    DisjointSet(int V){
        rank.resize(V+1,0);
        parent.resize(V+1,0);
        for(int i=0;i<=V;i++)
        parent[i]=i;
        
    }
    int finduparent(int node){
        if(parent[node]==node)
        return node;
        else
        return parent[node]= finduparent(parent[node]);
    }
    void unionbyrank(int x,int y){
        int xup=finduparent(x);
        int yup=finduparent(y);
        if(rank[xup]>rank[yup]){
            parent[yup]=xup;
        }
        else if(rank[yup]>rank[xup]){
            parent[xup]=yup;
        }
        else{
             parent[yup]=xup;
             rank[xup]++;
            
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0,maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet st(maxrow+maxcol+1);
        unordered_map<int,int>stonenodes;
        for(auto it:stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            st.unionbyrank(noderow,nodecol);
            stonenodes[noderow]=1;
            stonenodes[nodecol]=1;
            
        }
        int cnt=0;
        for(auto it:stonenodes){
            if(st.finduparent(it.first)==it.first)
                cnt++;
        }
        return stones.size()-cnt;
        
    }
};