class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int val = 1;

        while (top <= bottom && left <= right) {

            for (int j = left; j <= right; j++)
                ans[top][j] = val++;
            top++;

            for (int i = top; i <= bottom; i++)
                ans[i][right] = val++;
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans[bottom][j] = val++;
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans[i][left] = val++;
                left++;
            }
        }

        return ans;
    }
};