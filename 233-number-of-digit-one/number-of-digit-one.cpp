class Solution {
public:
    int countDigitOne(int n) {
        long long a=1,r=0;
        while(a<=n){
            long long l=n/(a*10);
            long long c=(n/a)%10;
            long long h=n%a;
            if(c==0)r+=l*a;
            else if(c==1)r+=l*a+h+1;
            else r+=(l+1)*a;
            a*=10;
        }
        return r;
    }
};