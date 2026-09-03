class Solution {
public:
    int minDistance(string word1, string word2) {
        int row=word1.size();
        int col=word2.size();
        vector<vector<int>> dp(row+1,vector<int>(col+1));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return (row-dp[row][col])+(col-dp[row][col]);
    }
};