class Solution {
public:
    int ladderLength(string bg, string ed, vector<string>& wl) {
        unordered_set<string> st(wl.begin(),wl.end());
        if(!st.count(ed)) return 0;

        queue<string> q;
        q.push(bg);
        int lv=1;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string wd=q.front();
                q.pop();
                if(wd==ed) return lv;
                for(int i=0;i<wd.size();i++){
                    char c=wd[i];
                    for(char j='a';j<='z';j++){
                        wd[i]=j;
                        if(st.count(wd)){
                            q.push(wd);
                            st.erase(wd);
                        }
                    }
                    wd[i]=c;
                }
            }
            lv++;
        }
        return 0;
    }
};