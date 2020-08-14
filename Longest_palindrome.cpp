class Solution {
public:
    int longestPalindrome(string s) {
        int max_len = 1010;
        unordered_map<char,int> map;
        for(auto c:s){
            map[c] += 1;
        }
        
        int odd=0,even=0;
        int odd_sum = 0,even_sum = 0;
        for(auto p:map){
            int count = p.second;
            if(count%2){
                odd += 1;
                odd_sum += count;
            }
            else{
                even +=1;
                even_sum += count;
                
            }
        }
        return even_sum + (odd ? odd_sum-(odd-1):0);
    }
};
