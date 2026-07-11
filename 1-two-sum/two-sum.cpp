class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
   int n= nums.size();

        map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int f = target - nums[i];
            if(mpp.find(f)!=mpp.end()){
                ans.push_back(mpp[f]);
                ans.push_back(i);
            }
            mpp[nums[i]]=i;
        }
   return ans; }
};