class Solution {
public:
    int titleToNumber(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            count *= 26;
            count += s[i] - 'A' + 1;
        }
        return count;
    }
};
