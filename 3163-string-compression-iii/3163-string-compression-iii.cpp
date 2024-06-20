class Solution {
public:
    string compressedString(string word) {
        string comp;
        int j=0;
        while(j<word.length()){
            int currlen=0;
            char c=word[j];
            while(word[j]==c&&currlen<=9){
                j++;
                currlen++;
            }
            if(currlen==10){
                currlen--;
                j--;
            }
            comp+=to_string(currlen);
            comp+=c;
        }
        return comp;
        
    }
};