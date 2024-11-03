class Solution {
public:
    bool rotateString(string A, string B) {
   queue<int>q,q1;
   int n=A.size(); 
    for(int i=0;A[i]!='\0';i++){
        q.push(A[i]);
		 q1.push(B[i]);
       }
	   
    //if the string A and B are equal
        if(A==B){
            return true;
        }  
		
      int i=0;
     while(i<n){
        q.push(q.front());
            q.pop();
            if(q==q1)
                return true;
            i++;
        }
      return false; 
    }
};