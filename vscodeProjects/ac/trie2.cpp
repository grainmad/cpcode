#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXN 10005
#define SIGMA 26

int tr[MAXN][SIGMA];//数组结构存储字典树
bool iskey[MAXN];//标记是否为关键字
int sz;//当前字典树中的节点数

//初始化
void tr_init() {
    memset(tr, 0, sizeof(tr));
    memset(iskey, 0, sizeof(iskey));
    sz = 1;
}

//插入
void tr_insert(char* s) {
    int len = strlen(s), u = 0;
    for (int i=0; i<len; i++) {
        int idx = s[i]-'a';
        if (tr[u][idx] == 0) {
            tr[u][idx] = sz++;
        }
        u = tr[u][idx];
    }
    iskey[u] = true;
}

//查询
bool tr_query(char* s) {
    int len = strlen(s), u = 0;
    for (int i=0; i<len; i++) {
        int idx = s[i]-'a';
        if (tr[u][idx] == 0) {
            return false;
        }
        u = tr[u][idx];
    }
    return iskey[u];
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