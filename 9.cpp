class Solution {
    struct Orange{
        int  i,j,day;  
    };
    const int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int today=0;
        int fresh = 0;
        
        queue<Orange> rotten;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 2){
                    rotten.push(Orange{i,j,0});
                }
                else if(grid[i][j] == 1){
                    fresh += 1;
                }
            }
        }
        while(!rotten.empty()){
            Orange &orange = rotten.front();
            int i=orange.i;
            int j = orange.j;
            
            if(orange.day > today){
                today++;
            }
            
            for(int d=0;d<4;d++){
                int x = i+ direction[d][0];
                int y = j+ direction[d][1];
                
                if(x>=0 && x<grid.size() && y>=0 && y<grid[i].size() && grid[x][y] == 1){
                    grid[x][y] = 2;
                    rotten.push(Orange{x,y,today+1});
                    fresh--;
                    
                }
            }
            rotten.pop();
            
                
        }
        return (fresh ==0)?today:-1;
    }
};
