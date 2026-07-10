class Solution {
public:
void bt(vector<int> &arr, vector<vector<int>> &ans, vector<int> &comb,set<vector<int>> &st,int idx, int target){
    if(target==0){
        if(st.find(comb)==st.end()){
            ans.push_back(comb);
            st.insert(comb);
        }
        return;

    }
    if(idx>=arr.size() || target<0)
    return;

    comb.push_back(arr[idx]);
    bt(arr,ans,comb,st,idx+1,target-arr[idx]);
    bt(arr,ans,comb,st,idx,target-arr[idx]);

    comb.pop_back();
    bt(arr,ans,comb,st,idx+1,target);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        set<vector<int>> st;
        bt(candidates,ans,comb,st,0,target);
        return ans;
    }
};