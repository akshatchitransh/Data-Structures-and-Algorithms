class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n=cit.size(),low=0,hig=n-1;
        while(low<=hig){
            int mid=(low+hig)/2;
            if(cit[mid]>=n-mid) hig=mid-1;
            else low=mid+1;
        }
        return n-low;
    }
};