class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        const int M=2048;
        vector<bool> p(M),v(M);
        int n=a.size();
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                p[a[i]^a[j]]=1;
        for(int x=0;x<M;x++){
            if(!p[x]) continue;
            for(int y:a)
                v[x^y]=1;
        }
        int ans=0;
        for(bool x:v) ans+=x;
        return ans;
    }
};