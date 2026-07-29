class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int idx, int val) {
        set<long long> st;
        for(int i=0;i<nums.size();i++){
            auto it=st.lower_bound((long long)nums[i]-val);
            if(it!=st.end()&&*it<=(long long)nums[i]+val) return true;
            st.insert(nums[i]);
            if(i>=idx) st.erase(nums[i-idx]);
        }
        return false;
    }
};