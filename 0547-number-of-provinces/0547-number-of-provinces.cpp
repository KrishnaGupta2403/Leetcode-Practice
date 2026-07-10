class Solution {
public:
//dfs
// void dfs(vector<vector<int>>& isConnected,int n, vector<bool>& visited,int i){
//     visited[i]=true;
//     for(int j=0;j<n;j++){
//         if(!visited[j] && isConnected[i][j]==1)
//         dfs(isConnected,n,visited,j);
//     }
// }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         int ans=0;
//         vector<bool> visited(n,false);
//         for(int i=0;i<n;i++){
           
//                 if(!visited[i]){
//                 dfs(isConnected,n,visited,i);
//                 ans++;
//                 }
            
//         }
//         return ans;
//     }
// };
int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       vector<bool> visited(n,false);
       queue<int> q;
       int ans=0;
       for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            q.push(i);
            while(!q.empty()){
                int top=q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(!visited[j] && isConnected[top][j]==1){
                        visited[j]=true;
                    q.push(j);
                    }
                }
            }
            ans++;
        }
       }
       return ans;
    }
};