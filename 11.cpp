class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int len = citations.size();
        int h= len;
        citations.push_back(0);
        
        for(int i=0;i<citations.size();i++){
            if(citations[i] <= len-i-1 && citations[i+1] >= len-i-1)
                h = len-i-1;     
            
        }
        return h;
    }
};
