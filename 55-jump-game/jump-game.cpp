class Solution {
public:
    bool dfs(vector<int>& nums, int i, vector<int>& dp) {

        if (i == nums.size() - 1)
            return true;

        if (i >= nums.size())
            return false;

        if (dp[i] != -1)
            return dp[i];

        bool ans = false;

        for (int j = 1; j <= nums[i]; j++) {
            bool x = dfs(nums, i + j, dp);
            ans = ans || x;

            if (ans) break;   // already found a valid path
        }

        return dp[i] = ans;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(nums, 0, dp);
    }
};