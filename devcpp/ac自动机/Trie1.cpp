class Trie {
public:
    struct Node {
        bool isKey;
        Node* son[26];
    }* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* u = root;
        for (int i=0; i<word.size(); i++) {
            if (u->son[word[i]-'a'] == NULL) {
                u->son[word[i]-'a'] = new Node();
            }
            u = u->son[word[i]-'a'];
        }
        u->isKey = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* u = root;
        for (int i=0; i<word.size(); i++) {
            if (u->son[word[i]-'a'] == NULL) {
                return false;
            }
            u = u->son[word[i]-'a'];
        }
        return u->isKey;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Node* u = root;
        for (int i=0; i<prefix.size(); i++) {
            if (u->son[prefix[i]-'a'] == NULL) {
                return false;
            }
            u = u->son[prefix[i]-'a'];
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

