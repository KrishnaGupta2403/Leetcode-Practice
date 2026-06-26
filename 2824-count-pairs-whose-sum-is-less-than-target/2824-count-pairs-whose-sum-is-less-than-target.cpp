class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        int ans=0;
        while(l<=r){
            int sum=nums[l]+nums[r];
            if(sum<target){
                ans+=(r-l);
                l++;
            }
            else
            r--;
        }
        return ans;
    }
};