class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;
        int ans=0;
        
        while(n!=0)
        {
            int rem=n%10;
            nums.push_back(rem);
            n=n/10;
        }
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                int temp=nums[i]*nums[j];
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};