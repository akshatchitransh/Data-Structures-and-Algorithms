class Solution {
public:
    void wiggleSort(vector<int>& a) {
        vector<int> b=a;
        sort(b.begin(),b.end());
        int n=a.size();
        int l=(n-1)/2,r=n-1;
        for(int i=0;i<n;i++){
            if(i&1) a[i]=b[r--];
            else a[i]=b[l--];
        }
    }
};