class Solution {
public:
int getmin(vector<int> &freq){
    int Min=INT_MAX;
    for(int i=0;i<freq.size();i++){
        if(freq[i]!=0)
        Min=min(freq[i],Min);
    }
    return Min;
}
int getmax(vector<int> &freq){
    int Max=0;
    for(int i=0;i<freq.size();i++){
        Max=max(freq[i],Max);
    }
    return Max;
}
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int> freq(26,0);
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;
                int beauty= getmax(freq)-getmin(freq);
                ans+=beauty;
            }
        }
        return ans;
    }
};