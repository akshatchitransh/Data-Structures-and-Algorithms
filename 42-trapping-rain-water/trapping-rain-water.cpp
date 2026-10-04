class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i=0;
        int j = n-1;
        int leftm = 0;
        int rightm = 0;
        int ans =0;
        while(i<j){
           
            if(height[i]<=height[j]){
                 leftm = max(leftm,height[i]);
                ans+= leftm-height[i];
                i++;

            }
            else{
                rightm = max(rightm,height[j]);
                   ans+= rightm-height[j];
                j--;
            }
        
        }
   return ans; }
};