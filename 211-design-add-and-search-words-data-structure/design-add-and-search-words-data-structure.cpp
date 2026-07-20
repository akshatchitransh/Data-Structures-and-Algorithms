class TrieNode {
public:
    TrieNode* nxt[26];
    bool end;

    TrieNode() {
        end = false;
        for (int iii = 0; iii < 26; iii++) nxt[iii] = nullptr;
    }
};

class WordDictionary {
public:
    TrieNode* roo;

    WordDictionary() {
        roo = new TrieNode();
    }

    void addWord(string wrd) {
        TrieNode* cur = roo;

        for (char chh : wrd) {
            int idx = chh - 'a';
            if (!cur->nxt[idx]) cur->nxt[idx] = new TrieNode();
            cur = cur->nxt[idx];
        }

        cur->end = true;
    }

    bool dfs(string &wrd, int pos, TrieNode* nod) {
        if (!nod) return false;

        if (pos == wrd.size()) return nod->end;

        if (wrd[pos] == '.') {
            for (int iii = 0; iii < 26; iii++) {
                if (dfs(wrd, pos + 1, nod->nxt[iii])) return true;
            }
            return false;
        }

        return dfs(wrd, pos + 1, nod->nxt[wrd[pos] - 'a']);
    }

    bool search(string wrd) {
        return dfs(wrd, 0, roo);
    }
};