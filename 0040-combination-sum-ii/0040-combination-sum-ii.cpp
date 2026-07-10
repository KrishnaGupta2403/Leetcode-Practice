class Solution {
public:
void bt(vector<int> &arr, vector<vector<int>>&ans, vector<int> &comb, int i, int target){
    if(target==0){
       
            ans.push_back(comb);
            
        
        return;
    }
    if(i>=arr.size() || target<0)
    return;

    for(int j=i;j<arr.size();j++){
        if(j>i && arr[j]==arr[j-1])
        continue;

        comb.push_back(arr[j]);
        bt(arr,ans,comb,j+1,target-arr[j]);
        comb.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        // set<vector<int>> st;
        sort(candidates.begin(),candidates.end());
        bt(candidates,ans,comb,0,target);
        return ans;
    }
};