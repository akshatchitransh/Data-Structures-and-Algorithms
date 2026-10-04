class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i=0;
        int j = n-1;
        int leftm = height[0];
        int rightm = height[n-1];
        int ans =0;
        while(i<j){
           
            if(leftm<=rightm){
                 leftm = max(leftm,height[i]);
                 if(leftm<=rightm){
                     ans+= leftm-height[i];
                i++;
                 }
                 else continue;
                

            }
            else{
                rightm = max(rightm,height[j]);
                if(rightm<leftm){
 ans+= rightm-height[j];
                j--;
                }
                else continue;
                  
            }
        
        }
   return ans; }
};