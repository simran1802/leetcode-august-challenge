class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int start=0;
        int end = a.size()-1;
        while(end>=0 && a[end]%2==1)
            end--;
        while(start< end){
            if(a[start]%2==0)
                start++;
            else{
                swap(a[start],a[end]);
                start++;
                end--;
                
                while(end>=0 && a[end]%2==1)
                    end--;
            }
        }
        return a;
    }
};
