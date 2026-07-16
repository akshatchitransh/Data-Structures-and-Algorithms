class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a,int k) {
        deque<int> d;
        vector<int> r;
        for(int i=0;i<a.size();i++){
            while(!d.empty()&&d.front()<=i-k)d.pop_front();
            while(!d.empty()&&a[d.back()]<=a[i])d.pop_back();
            d.push_back(i);
            if(i>=k-1)r.push_back(a[d.front()]);
        }
        return r;
    }
};