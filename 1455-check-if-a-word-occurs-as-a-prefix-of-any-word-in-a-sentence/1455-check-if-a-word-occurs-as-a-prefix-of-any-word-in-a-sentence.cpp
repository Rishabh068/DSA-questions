class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i=0,j=0,word=1;
        while(i<sentence.length()){
            if((i==0||sentence[i-1]==' ')&&sentence[i]==searchWord[j]){
                while(i<sentence.length()&&j<sentence.length()&&sentence[i]==searchWord[j]){
                    i++;
                    j++;
                }
                if(j==searchWord.length())
                    return word;
                
            }
            j=0;
                if(sentence[i]==' ')
                    word++;
            i++;
        }
        return -1;
        
    }
};