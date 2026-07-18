class Solution {
public:
int gcd_self(int a,int b){
    if(b==0)
    return abs(a);

    return gcd_self(b,a%b);
}
    int findGCD(vector<int>& v) {
        int max,min;
        min=*min_element(v.begin(),v.end());
        max=*max_element(v.begin(),v.end());
        int Gcd= gcd_self(max,min);
        return Gcd;
        
    }
};