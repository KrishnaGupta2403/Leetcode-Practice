class Solution {
public:
bool ispalindrome(int i,int j, string &s, vector<vector<int>> &dp){
   if(i>=j)
   return true;

    if(dp[i][j]!=-1)
    return dp[i][j];
   if(s[i]==s[j])
     return dp[i][j]= ispalindrome(i+1,j-1,s,dp);

    return false;

   
}
    string longestPalindrome(string s) {
        int maxlen=INT_MIN;
        int start=-1;
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrome(i,j,s,dp)){
                    if(j-i+1> maxlen){
                        maxlen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};