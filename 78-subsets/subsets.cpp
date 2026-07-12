class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(idx + 1, nums);
        temp.pop_back();

        solve(idx + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};