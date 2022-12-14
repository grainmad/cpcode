#define MAXN 100005
#define SIGMA 26
class Trie {
public:
    int tr[MAXN][SIGMA];
    bool val[MAXN];
    int sz;
    /** Initialize your data structure here. */
    Trie() {
        memset(tr, 0, sizeof(tr));
        memset(val, 0, sizeof(val));
        sz = 1;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int u = 0;
        for (int i=0; i<word.size(); i++) {
            if (tr[u][word[i]-'a'] == 0) {
                tr[u][word[i]-'a'] = sz++;
            }
            u = tr[u][word[i]-'a'];
        }
        val[u] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int u = 0;
        for (int i=0; i<word.size(); i++) {
            if (tr[u][word[i]-'a'] == 0) {
                return false;
            }
            u = tr[u][word[i]-'a'];
        }
        return val[u];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int u = 0;
        for (int i=0; i<prefix.size(); i++) {
            if (tr[u][prefix[i]-'a'] == NULL) {
                return false;
            }
            u = tr[u][prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
