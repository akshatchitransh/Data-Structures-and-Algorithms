class Solution {
public:
    unordered_map<string,vector<int>> dp;

    vector<int> diffWaysToCompute(string s) {
        if(dp.count(s))return dp[s];
        vector<int> r;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='+'||c=='-'||c=='*'){
                vector<int> l=diffWaysToCompute(s.substr(0,i));
                vector<int> x=diffWaysToCompute(s.substr(i+1));
                for(int a:l)for(int b:x){
                    if(c=='+')r.push_back(a+b);
                    else if(c=='-')r.push_back(a-b);
                    else r.push_back(a*b);
                }
            }
        }
        if(r.empty())r.push_back(stoi(s));
        return dp[s]=r;
    }
};