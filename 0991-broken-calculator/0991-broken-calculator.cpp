class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(startValue!=target){
            if(target>startValue){
                if(target%2==0)
                target/=2;
                else
                target+=1;

                ans++;
            }
            else{
                ans+=(startValue-target);
                target+=(startValue-target);
                
            }
        }
        return ans;
    }
};