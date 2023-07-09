// Trie
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1000005
#define SIGMA 26
// 仅含小写英文字母
using namespace std;
struct Trie {
    int tr[MAXN][SIGMA];  // 数组存储Trie树节点,下标起到指针作用
    int val[MAXN];  // 若当前节点不是一个模式串的结尾则为0
    int sz;         // Trie中当前节点个数
    Trie() {
        memset(tr, 0, sizeof(tr));
        memset(val, 0, sizeof(val));
        sz = 1;
    }
    // 插入
    void insert(char* s) {
        int len = strlen(s), u = 0;
        for (int i = 0; i < len; i++) {
            if (tr[u][s[i] - 'a'] == 0) {  // 不存在新开就一个节点
                tr[u][s[i] - 'a'] = sz;
                sz++;
            }
            u = tr[u][s[i] - 'a'];
        }
        val[u] = 1;
    }
    // 查询s是否存在
    bool query(char* s) {
        int len = strlen(s), u = 0;
        for (int i = 0; i < len; i++) {
            if (tr[u][s[i] - 'a'] == 0)
                return false;
            u = tr[u][s[i] - 'a'];
        }
        return val[u];
    }
};  // namespace Trie

char txt[100];
char pat[5][100] = {"i", "she", "his", "hers", "he"};

int main() {
    Trie trie;
    for (int i = 0; i < 5; i++) {
        trie.insert(pat[i]);
    }
    while (1) {
        cin >> txt;
        cout << trie.query(txt) << endl;
    }
    return 0;
}
