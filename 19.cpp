class Solution {
public:
    string toGoatLatin(string s) {
        string ans="";
        char aux;
        int l=1,f;
        for(int i=0;i<s.length();i++){
            f=0;
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                    ans+=s[i];       // if vowel then directly append to resulting string
                }
                else{
                    f=1;
                    aux=s[i];        // if consonant then store that character so that we later append
                }
                i++;
                while(i<s.length() && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))){
                    ans+=s[i];        // append all the rest characters of a word
                    i++;
                }
                if(f==1)
                 ans+=aux;
                ans+="ma";
                for(int j=0;j<l;j++)         // appending 'a' according to word index
                 ans+='a';
                if(i<s.length())             // add space only when the word is not a last word
                 ans+=" "; 
                l++;
            }
        }
        return ans;
    }
};
