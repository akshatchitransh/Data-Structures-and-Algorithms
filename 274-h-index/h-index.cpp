class Solution {
public:
    int hIndex(vector<int>& a) {
        sort(a.begin(),a.end(),greater<int>());
        int n=a.size(),r=0;
        for(int i=0;i<n;i++){
            if(a[i]>=i+1)r=i+1;
            else break;
        }
        return r;
    }
};