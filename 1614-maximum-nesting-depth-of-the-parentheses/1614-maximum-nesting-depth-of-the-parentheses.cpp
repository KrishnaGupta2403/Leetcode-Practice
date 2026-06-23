class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int depth=0,left=0,right=0;
        for(char c: s){
            if(c=='(')
            left++;
            else if(c==')')
            right++;
            else
            continue;

            depth=abs(left-right);
            ans=max(ans,depth);
        }
        return ans;
    }
};