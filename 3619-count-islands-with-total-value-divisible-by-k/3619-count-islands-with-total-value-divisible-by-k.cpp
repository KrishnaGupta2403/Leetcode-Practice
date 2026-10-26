class Solution {
public:
long long dfs(vector<vector<int>> &grid, int i,int j, int row,int col){
    if(i<0 || i>=row ||j<0 ||j>=col || grid[i][j]==0)
    return 0;

    long long sum = grid[i][j];
    grid[i][j]=0;
    sum+=dfs(grid,i+1,j,row,col);
    sum+=dfs(grid,i-1,j,row,col);
    sum+=dfs(grid,i,j+1,row,col);
    sum+=dfs(grid,i,j-1,row,col);

    return sum;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=0){
                    long long sum=dfs(grid,i,j,row,col);
                
                    if(sum!=0 && sum%k==0)
                    ans++;
                }
            }
        }
        return ans;
    }
};