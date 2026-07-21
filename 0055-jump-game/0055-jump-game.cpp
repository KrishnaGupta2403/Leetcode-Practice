class Solution {
public:
bool rec(int idx,vector<int>&nums,vector<int> &dp){
    if(idx>=nums.size()-1)
    return true;

    if(dp[idx]!=-1)
    return dp[idx];

    int jump=nums[idx];
    for(int i=1;i<=jump;i++){
        if(rec(idx+i,nums,dp))
        return dp[idx]=1;
    }
    return dp[idx]=0;
}
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        
        return rec(0,nums,dp);
    }
};