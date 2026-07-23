class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> ad(n);
        vector<int> in(n);
        for(auto &x:p){
            ad[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
            if(!in[i]) q.push(i);

        int ct=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ct++;
            for(int v:ad[u])
                if(--in[v]==0)
                    q.push(v);
        }
        return ct==n;
    }
};