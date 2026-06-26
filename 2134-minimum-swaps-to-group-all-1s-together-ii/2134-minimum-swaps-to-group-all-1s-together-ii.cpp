class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int ones = 0;
        for (int x : nums)
            ones += x;

        if (ones == 0 || ones == n)
            return 0;

        nums.insert(nums.end(), nums.begin(), nums.end());

        int zero = 0;

        for (int i = 0; i < ones; i++) {
            if (nums[i] == 0)
                zero++;
        }

        int ans = zero;

        int l = 0, r = ones;

        while (l < n) {
            if (nums[l] == 0)
                zero--;
            l++;

            if (nums[r] == 0)
                zero++;
            r++;

            ans = min(ans, zero);
        }

        return ans;
    }
};