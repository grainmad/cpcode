#include <bits/stdc++.h>
#define N 505
using namespace std;

pair<int, int> fa[N][N];  // fa[i][j] 为网格s[x][y]的父节点
string s[N];              // s[x][y] 地x行y列的网格
int n, m, b;              // n 行 m 列 b 个障碍
int sx, sy, ex, ey;       // 开始位置(sx, sy) 目标位置(ex, ey)

// 读入地图
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

// 地图节点 重载<运算符 实现节点的评估函数f比较
struct Node {
    int x, y, dis;
    int g() const { return dis; }
    double h() const { return (abs(x - ex) + abs(y - ey)) * 1.000; }
    double abs_cross(int x, int y) const {
        return abs((x - sx) * (ey - sy) - (y - sy) * (ex - sx)) * 0.001;
    }
    bool operator<(const Node& o) const {
        if (g() + h() == o.g() + o.h()) {
            return abs_cross(x, y) > abs_cross(o.x, o.y);
        }
        return g() + h() > o.g() + o.h();  // priority_queue 默认大根堆
    }
    Node(int _x, int _y, int _dis) : x(_x), y(_y), dis(_dis) {}
};

// 通过fa指针回溯找到搜索路径
void setpath(int x, int y) {
    if (x == sx && y == sy)
        return;
    s[x][y] = '*';
    setpath(fa[x][y].first, fa[x][y].second);
}

// 0.2秒清空控制台输出一次
void print() {
    system("cls");
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    _sleep(200);
}

// 主函数
// 我们用优先队列priory_queue<Node>维护open集合，优先从中选取最小的f的节点。
int main() {
    init_map();
    print();
    priority_queue<Node> q;
    q.push({sx, sy, 0});
    while (q.size()) {
        auto node = q.top();
        q.pop();
        if (node.x == ex && node.y == ey)
            break;
        if (node.x != sx && node.y != sy)
            s[node.x][node.y] = 'C';
        print();
        for (int i = 0; i < 4; i++) {
            int x = node.x + (i - 1) % 2, y = node.y + (i - 2) % 2;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (s[x][y] == 'E') {
                setpath(node.x, node.y);
                print();
                return 0;
            }
            if (s[x][y] == '.') {
                q.emplace(x, y, node.dis + 1);
                fa[x][y] = {node.x, node.y};
                s[x][y] = 'O';
                print();
            }
        }
    }
    return 0;
}