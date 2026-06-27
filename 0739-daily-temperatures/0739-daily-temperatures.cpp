class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        stack<int> st;// push index

        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                int top=st.top();
                ans[top]=i-top;
                st.pop();
            }
            st.push(i);
        }
         while(!st.empty()){
                int top=st.top();
                ans[top]=0;
                st.pop();
            }
        return ans;
    }
};