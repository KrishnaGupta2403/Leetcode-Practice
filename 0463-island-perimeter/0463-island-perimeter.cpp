class Solution {
public:
int dfs(vector<vector<int>>& grid, int i,int j,int row,int col){
    if(i>=row || i<0|| j<0|| j>=col)
    return 1;

    if(grid[i][j]==0)
    return 1;
    if(grid[i][j]==-1)
    return 0;
    grid[i][j]=-1;
    int ans=0;
    ans+=dfs(grid,i-1,j,row,col);
    ans+=dfs(grid,i+1,j,row,col);
    ans+=dfs(grid,i,j-1,row,col);
    ans+=dfs(grid,i,j+1,row,col);
    return ans;
}
    int islandPerimeter(vector<vector<int>>& grid) {
       int row=grid.size();
       int col=grid[0].size();
     
       for(int i=0;i<row ;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==0)
            continue;
            return dfs(grid,i,j,row,col);
        }
       } 
       return 0;
    }
};