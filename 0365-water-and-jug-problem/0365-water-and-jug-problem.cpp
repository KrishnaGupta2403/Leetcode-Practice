class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int z=x+y;
        vector<int> dir={-x,x,-y,y};
        queue<int> q;
        vector<int> vis(z+1,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(curr==target)
            return true;

            for(int i=0;i<4;i++){
                int newcurr=curr+dir[i];
                if(newcurr>=0 && newcurr<=z && !vis[newcurr]){
                    q.push(newcurr);
                    vis[newcurr]=1;
                }
            }
        }
        return false;
    }
};