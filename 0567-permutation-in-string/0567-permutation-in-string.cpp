class Solution {
public:
    bool checkInclusion(string p, string s) {
         unordered_map<char,int> first;
        unordered_map<char,int> second;
        vector<int> ans;
        int n=p.size();
        int i=0,j=0;
        for(int i=0;i<p.size();i++){
            first[p[i]]++;
        }
        while(j<s.size()){
            if(j-i+1>n)
            {
                second[s[i]]--;
                if(second[s[i]]==0)
                second.erase(s[i]);

                i++;
            }
            second[s[j]]++;
            j++;
            if(first==second)
            return true;
        }
        return false;
    }
};