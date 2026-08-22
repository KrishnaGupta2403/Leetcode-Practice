class Solution {
    void rev(int l,int r, int[] nums){
        while(l<r){
            int temp=nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            l++;
            r--;
        }
    }
    public void rotate(int[] nums, int k) {
       int n=nums.length;
       k=k%n;
       rev(0,n-1,nums);
       rev(0,k-1,nums);
       rev(k,n-1,nums);

    }
}