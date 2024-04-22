class Solution {
public:
    void addnodes(queue<string>&q,unordered_set<string>&deadend,string pattern){
        for(int i=0;i<4;i++){
            char ch=pattern[i];
            char plus=ch=='9'?'0':ch+1;
            char minus=ch=='0'?'9':ch-1;
            pattern[i]=plus;
            if(deadend.find(pattern)==deadend.end()){
                q.push(pattern);
                deadend.insert(pattern);
            }
            pattern[i]=minus;
              if(deadend.find(pattern)==deadend.end()){
                q.push(pattern);
                deadend.insert(pattern);
            }
            pattern[i]=ch;
            
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>deadend;
        for(auto it:deadends){
            deadend.insert(it);
        }
        if(deadend.find("0000")!=deadend.end())
            return -1;
        int moves=0;
      queue<string>q;
        q.push("0000");
        deadend.insert("0000");
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string pattern=q.front();
                q.pop();
                if(pattern==target)
                    return moves;
                addnodes(q,deadend,pattern);
            }
            moves++;
        }
        return -1;
        
    }
};