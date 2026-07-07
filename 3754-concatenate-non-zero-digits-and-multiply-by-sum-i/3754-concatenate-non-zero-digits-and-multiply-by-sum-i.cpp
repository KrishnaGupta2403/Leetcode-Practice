class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0;
        string s="";
        while(n!=0){
            int rem=n%10;
            if(rem!=0)
            s+=to_string(rem);
            n=n/10;
        }
        reverse(s.begin(),s.end());
        for(char c: s){
            int x=c-'0';
            num=num*10+x;
        }
        long long sum=0;
        long long temp=num;
         while(temp!=0){
            int rem=temp%10;
            sum+=rem;
            temp/=10;
        }
        return sum*num;
    }
};