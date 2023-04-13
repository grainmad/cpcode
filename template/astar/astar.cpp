#include <bits/stdc++.h>
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

string s[N];
int n, m, b;
int sx, sy, ex, ey;

void init_map() {
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S')
                sx = i, sy = j;
            if (s[i][j] == 'E')
                ex = i, ey = j;
        }
    }
}

struct Node {
    int x, y, dis;
    int g() const { return dis; }
    int h() const { return abs(x - ex) + abs(y - ey); }
    int abs_cross(int x, int y) const {
        return abs((x - sx) * (ex - sx) - (y - sy) * (ey - sy));
    }
    bool operator<(const Node& o) const {
        if (g() + h() == o.g() + o.h()) {
            return abs_cross(x, y) > abs_cross(o.x, o.y);
        }
        return g() + h() > o.g() + o.h();
    }
    Node(int _x, int _y, int _dis) : x(_x), y(_y), dis(_dis) {}
};

void print() {
    system("cls");
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    _sleep(200);
}

int main() {
    init_map();
    print();
    priority_queue<Node> q;
    q.push({sx, sy, 0});
    s[sx][sy] = 'Q';
    print();
    while (q.size()) {
        auto node = q.top();
        q.pop();
        if (node.x == ex && node.y == ey) {
            break;
        }
        s[node.x][node.y] = 'D';
        print();
        for (int i = 0; i < 4; i++) {
            int x = node.x + (i - 1) % 2;
            int y = node.y + (i - 2) % 2;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (s[x][y] == '.' || s[x][y] == 'E') {
                q.emplace(x, y, node.dis + 1);
                s[x][y] = 'Q';
                print();
            }
        }
    }
    return 0;
}