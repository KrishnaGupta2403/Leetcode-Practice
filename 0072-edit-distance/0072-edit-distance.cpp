class Solution {
public:
    int solve(string& s1, string &s2, int i,int j, int m, int n, vector<vector<int>> &dp){
        if(i==m)
        return n-j;
        if(j==n)
        return m-i;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s1[i]==s2[j])
        return dp[i][j]=solve(s1,s2,i+1,j+1,m,n,dp);

        else{
            int insert=1+solve(s1,s2,i,j+1,m,n,dp);
            int del=1+solve(s1,s2,i+1,j,m,n,dp);
            int replace=1+solve(s1,s2,i+1,j+1,m,n,dp);

            return dp[i][j]=min({insert,del,replace});
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return solve(word1,word2,0,0,m,n,dp);

        
    }
};