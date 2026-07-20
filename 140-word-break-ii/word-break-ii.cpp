class Solution {
public:
    unordered_set<string> stt;
    unordered_map<string, vector<string>> mem;

    vector<string> dfs(string str) {
        if (mem.count(str)) return mem[str];

        vector<string> ans;

        if (str.empty()) {
            ans.push_back("");
            return ans;
        }

        for (int iii = 1; iii <= str.size(); iii++) {
            string pre = str.substr(0, iii);

            if (stt.count(pre)) {
                vector<string> tmp = dfs(str.substr(iii));

                for (string &suf : tmp) {
                    if (suf.empty())
                        ans.push_back(pre);
                    else
                        ans.push_back(pre + " " + suf);
                }
            }
        }

        return mem[str] = ans;
    }

    vector<string> wordBreak(string str, vector<string>& dic) {
        for (string &wrd : dic) stt.insert(wrd);
        return dfs(str);
    }
};