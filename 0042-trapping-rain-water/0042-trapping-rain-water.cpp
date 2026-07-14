class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);
        int max=height[0];
        for(int i=0;i<n;i++){
            if(i==0)
            leftmax[i]=max;

            else if(height[i]>max){
                max=height[i];
                leftmax[i]=max;
            }
            else{
                leftmax[i]=max;
            }
        }
        max=height[n-1];
        for(int i=n-1;i>=0;i--){
            if(i==n-1)
            rightmax[i]=max;

            else if(height[i]>max){
                max=height[i];
                rightmax[i]=max;
            }
            else{
                rightmax[i]=max;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(leftmax[i],rightmax[i])-height[i]);
        }
        return ans;

    }
};