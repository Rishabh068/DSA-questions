class Solution {
public:
    set<string>ans;
    vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    class trienode{
        public: bool isendwithWord;
          string iword;
          trienode *children[26];
        trienode(){
            this->isendwithWord=false;
            this->iword="";
            for(int i=0;i<26;i++){
                this->children[i]=nullptr;
            }
        }
    };
    void insertWord(string word, trienode* root){
        trienode* crawler=root;
        for(int i=0;i<word.length();i++){
            if(crawler->children[word[i]-'a']==nullptr){
                crawler->children[word[i]-'a']=new trienode();
            }
            crawler=crawler->children[word[i]-'a'];
        }
        crawler->isendwithWord=true;
        crawler->iword=word;
    }
    void helper(vector<vector<char>>& board,trienode* root,int i,int j){
        if(i>=board.size()||i<0||j>=board[0].size()||j<0)
            return;
        if(board[i][j]=='$'||root->children[board[i][j]-'a']==nullptr)
            return;
        
        root=root->children[board[i][j]-'a'];
        if(root->isendwithWord==true)
            ans.insert(root->iword);
        
        char temp=board[i][j];
        board[i][j]='$';
        for(auto it:dir){
            int newx=i+it.first;
            int newy=j+it.second;
            helper(board,root,newx,newy);
        }
        board[i][j]=temp;    
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trienode* root=new trienode();

        for(auto it:words){
            insertWord(it,root);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(root->children[board[i][j]-'a']!=nullptr){
                    trienode* rt=root;
                    helper(board,rt,i,j);
                }
            }
        }
       vector<string>yy;
        for(auto it:ans){
            yy.push_back(it);
        }
        return yy;
        
    }
};