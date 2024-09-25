class Solution {
public:
    class trienode{
        public:
        int count;
        trienode *children[26];
        trienode(){
             this->count=0;
            for(int i=0;i<26;i++){
                this->children[i]=nullptr;
            }
        }
    };
    void insertword(trienode *root,string word){
        trienode* crawler=root;
        for(int i=0;i<word.length();i++){
            if(crawler->children[word[i]-'a']==nullptr){
                crawler->children[word[i]-'a']=new trienode();
            }
            crawler=crawler->children[word[i]-'a'];
                crawler->count++;
            
        }
    }
    int prefixcount(trienode *root,string word){
        int ans=0;
        trienode* crawler=root;
        for(int i=0;i<word.length();i++){
            if(crawler->children[word[i]-'a']==nullptr){
                break;
            }
            crawler=crawler->children[word[i]-'a'];
            ans+=crawler->count;
        }
        return ans;
        
        
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        trienode *root=new trienode();
        for(auto it:words){
            insertword(root,it);
        }
        vector<int>ans;
        for(auto it:words){
            ans.push_back(prefixcount(root,it));
        }
        return ans;
        
    }
};