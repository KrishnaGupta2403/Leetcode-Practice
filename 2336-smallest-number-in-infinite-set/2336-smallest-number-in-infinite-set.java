class SmallestInfiniteSet {
    PriorityQueue<Integer> pq;
    HashSet<Integer> st;
    int curr;
    public SmallestInfiniteSet() {
        pq=new PriorityQueue<>();
        st=new HashSet<>();
        curr=1;
    }
    
    public int popSmallest() {
        if(!pq.isEmpty()){
            int ans=pq.poll();
            st.remove(ans);
            return ans;
        }
        else{
            int ans=curr;
            curr++;
            return ans;
        }
    }
    
    public void addBack(int num) {
        if(num<curr && !st.contains(num)){
            pq.add(num);
            st.add(num);
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */