#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
    bool isKey;
    Node* son[26];
};
Node* root;
void tr_init() {
    root = new Node();
}

void tr_insert(char* s) {
    int len = strlen(s);
    Node* t = root;
    for (int i=0; i<len; i++) {
        int idx = s[i]-'a';
        if (t->son[idx] == NULL) {
            t->son[idx] = new Node();
        }
        t = t->son[idx];
    }
    t->isKey = true;
}

bool tr_query(char* s) {
    int len = strlen(s);
    Node* t = root;
    for (int i=0; i<len; i++) {
        int idx = s[i]-'a';
        if (t->son[idx] == NULL) {
            return false;
        }
        t = t->son[idx];
    }
    return t->isKey;
}

char s[10000];

int main() {
    tr_init();
    for (int i=0; i<3; i++) {
        scanf("%s", s);
        tr_insert(s);
    }
    scanf("%s", s);
    if (tr_query(s)) printf("yes");
    else printf("no");
    
    return 0;
}