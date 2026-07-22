class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        stringstream ss(s);
        string w;
        int i=0;
        while(ss>>w){
            if(i==p.size()) return 0;
            if(m1.count(p[i])&&m1[p[i]]!=w) return 0;
            if(m2.count(w)&&m2[w]!=p[i]) return 0;
            m1[p[i]]=w;
            m2[w]=p[i];
            i++;
        }
        return i==p.size();
    }
};