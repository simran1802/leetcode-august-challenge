class Solution {
    void fac(map <int,vector<int> > &mp,int a,int p){
        for(int i=1;i<=sqrt(a);i++){
            if(a%i==0){
                if(a/i==i)
                    mp[i].push_back(p);
                else 
                {
                    mp[i].push_back(p);
                    mp[a/i].push_back(p);
                }
            }
        }
    }
    void print(vector < vector<int> > &v){
        
        for(int i=0;i<v.size();i++){
            cout<<i<<" : ";
            for(int k=0;k<v[i].size();k++)
                 cout<<v[i][k]<<" ";
            cout<<endl;
        }
    }
    void dfs(vector <vector<int> > &g, vector<bool>&b,int s,int &t){
        stack <int> st;
        st.push(s);
        
        while(!st.empty()){
            int x=st.top();
            st.pop();
            if(b[x]==0){
                b[x]=1;
                t++;
                for(int j=0;j<g[x].size();j++){
                    if(b[g[x][j]]==0)
                        st.push(g[x][j]);
                        
                }
            }
        }
            
    }
public:
    int largestComponentSize(vector<int>& A) {
        
        map<int, vector<int> > mp;
        for(int i=0;i<A.size();i++){
            fac(mp,A[i],i);
        }
       
        vector < vector<int> > g(A.size());
        for(auto u : mp){
            if(u.second.size()>1 && u.first!=1){
                for(int i=0;i<u.second.size()-1;i++){
                    g[u.second[i]].push_back(u.second[i+1]);
                    g[u.second[i+1]].push_back(u.second[i]);
                }
            }
        }
        
        //print(g);
        
        int mc=1;
        vector <bool> b(A.size(),0);
        for(int j=0;j<b.size();j++){
            if(b[j]==0){
                int t=0;
                dfs(g,b,j,t);
                mc=max(mc,t);
                
            }
        }
        return mc;
        
        
        
    }
};
