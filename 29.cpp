class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        int n = A.size();
        for(int i=0;i<n;i++){
            int pos = 0;
            int max = INT_MIN;
            for(int j=0;j<n-i;j++){
                if(max < A[j]){
                    max = A[j];
                    pos = j;
                }
            }
            if(pos == n-i-1)
                continue;
            else{
                reverse(A.begin(),A.begin()+pos+1);
                result.push_back(pos+1);
                
                reverse(A.begin(),A.begin()+n-i);
                result.push_back(n-i);
            }
        }
        return result;
    }
};
