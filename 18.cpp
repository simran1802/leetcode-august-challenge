class Solution {
public:
    
    void generate_num(string s,int index,int n,int k,vector<int>& ans){
        if(s.size() == n){
            ans.push_back(stoi(s));
            return ;
        }
        int num = s[index] - 48;
        if(num+k <= 9){
            generate_num(s+to_string(num+k),index+1,n,k,ans);
        }
        if(num-k >= 0 && num-k != num+k){
            generate_num(s+to_string(num-k),index+1,n,k,ans);
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1)
            return {0,1,2,3,4,5,6,7,8,9};
        vector<int> result;
        for(int i=1;i<=9;i++){
            generate_num(to_string(i),0,N,K,result);
        }
        return result;
    }
};
