class Solution {
public:
  set<vector<int>> s;
void getcombination(vector<int> &arr, int target, int idx, vector<int> &comb, vector<vector<int>> &res) {
  
       if(target==0)
       {
        if(s.find(comb) ==s.end())
        {
            res.push_back({comb});
            s.insert({comb});
        }
        return;
       }
       if(idx>=arr.size() || target<0)
       return ;

       comb.push_back(arr[idx]);
       getcombination(arr,target-arr[idx],idx+1,comb,res);
       getcombination(arr,target-arr[idx],idx,comb,res);

       comb.pop_back();
       getcombination(arr,target,idx+1,comb,res);


        
    }
   vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
       getcombination(candidates, target, 0, comb,res);
        return res;        
    }
   
};