class Solution {
public:
    bool detectCapitalUse(string word) {
        // Case 1:
        if(int(word[0]) >= 65 && int(word[0]) <= 90 && int(word[1]) >= 65 && int(word[1]) <= 90){
            for(auto c: word){
                if(int(c) >= 65 && int(c)<= 90)
                    continue;
                else
                    return false;
            }
        }
        
        // Case 2:
        else if(int(word[0]) >= 97 && int(word[0]) <=123 && int(word[1]) >= 97 && int(word[1]) <= 123){
            for(auto c: word){
                if(int(c) >= 97 && int(c) <= 123)
                    continue;
                else
                    return false;
                
            }
        }
        
        // Case 3:
        else if(int(word[0]) >= 65 && int(word[0]) <=90 && int(word[1]) >= 97 && int(word[1]) <= 123){
            for(int i=2;i<word.length();i++){
                if(int(word[i]) >= 97 && int(word[i]) <= 123)
                    continue;
                else
                    return false;
                
            }
        }
        
        // Case 4: 1st letter small and rest are capital 
        else if ( int(word[0])>=97 && int(word[0])<=123 &&  int(word[1])>=65 && int (word[1])<=90)
        {
            return false;
        }
        
        return true;
    }
};
