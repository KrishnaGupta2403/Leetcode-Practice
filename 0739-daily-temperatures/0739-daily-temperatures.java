class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n=temperatures.length;
        int arr[]=new int [n];
        Arrays.fill(arr,0);
        Stack<Integer> st=new Stack<>();
        for(int i=0;i<n;i++){
            while(!st.isEmpty() && temperatures[i]>temperatures[st.peek()]){
                arr[st.peek()]=i-st.peek();
                st.pop();
            }
            st.push(i);
        }
        return arr;
    }
}