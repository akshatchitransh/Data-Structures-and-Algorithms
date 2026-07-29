class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long lon=0;
        for(int x:nums) lon^=x;
        lon&=-lon;
        int one=0,two=0;
        for(int x:nums){
            if(x&lon) one^=x;
            else two^=x;
        }
        return {one,two};
    }
};