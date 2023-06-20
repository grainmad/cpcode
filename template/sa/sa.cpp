#include <bits/stdc++.h>
using namespace std;

// 后缀数组，生成sa，rk，height数组
// range应大于串的长度和串元素最大值。串中元素值应非负。
template <class T = string, int range = 128>
struct SuffixArray {
    T s;
    int n, bucketRange;
    int sa[range], second[range], bucket[range], mem[range], rk_mem[range + 1],
        rk2_mem[range + 1], height[range], *rk, *rk2;
    SuffixArray(const T& _s) : s(_s), n(s.size()), bucketRange(range) {
        rk = rk_mem;
        rk2 = rk2_mem;
        rk[n] = rk2[n] = -1;
        memset(bucket, 0, sizeof(bucket));
        for (int i = 0; i < n; i++)
            bucket[rk[i] = s[i]]++;
        for (int i = 1; i < bucketRange; i++)
            bucket[i] += bucket[i - 1];
        for (int i = 0; i < n; i++)
            sa[--bucket[rk[i]]] = i;
        for (int w = 1;; w <<= 1) {
            int j = 0;
            for (int i = n - w; i < n; i++)
                second[j++] = i;
            for (int i = 0; i < n; i++)
                if (sa[i] >= w)
                    second[j++] = sa[i] - w;
            memset(bucket, 0, sizeof(bucket));
            for (int i = 0; i < n; i++)
                bucket[mem[i] = rk[second[i]]]++;
            for (int i = 1; i < bucketRange; i++)
                bucket[i] += bucket[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--bucket[mem[i]]] = second[i];
            bucketRange = 0;
            for (int i = 0; i < n; i++) {
                rk2[sa[i]] = !i || (rk[sa[i]] == rk[sa[i - 1]] &&
                                    rk[sa[i] + w] == rk[sa[i - 1] + w])
                                 ? bucketRange
                                 : ++bucketRange;
            }
            swap(rk, rk2);
            if (++bucketRange == n)
                break;
        }
    }
    // height[i] 为sa[i-1]与sa[i]的公共前缀长度。
    void getHeight() {
        memset(height, 0xff, sizeof(height));
        for (int i = 0, h = 0; i < n; i++) {
            if (h)
                h--;
            if (rk[i])
                while (sa[rk[i] - 1] + h < n &&
                       s[i + h] == s[sa[rk[i] - 1] + h])
                    h++;
            height[rk[i]] = h;
        }
    }
    // 获取后缀x与任意后缀的最长公共前缀长度。x in [0,n-1]
    vector<int> getLcp(int x) {  // 注意先要获取height
        vector<int> lcp(n, n);
        for (int i = rk[x], j = n; i >= 1; i--) {
            j = min(j, height[i]);
            lcp[sa[i - 1]] = j;
        }
        for (int i = rk[x] + 1, j = n; i < n; i++) {
            j = min(j, height[i]);
            lcp[sa[i]] = j;
        }
        return lcp;
    }
};
template <class T>
void suf(T& x, int p) {
    cout << "[";
    while (p < x.size()) {
        cout << x[p++] << ","[p == x.size()];
    }
    cout << "]" << endl;
}
int main() {
    // string s = "aabaaaab";
    vector<int> s = {1, 1, 2, 1, 1, 1, 1, 2};
    int n = s.size();
    SuffixArray<vector<int>, 8> SA(s);
    SA.getHeight();
    auto sa = SA.sa, rank = SA.rk, height = SA.height;

    cout << "sa" << endl;
    for (int i = 0; i < n; i++) {
        cout << "排名:" << i << " 后缀:" << sa[i] << " ";
        suf(s, sa[i]);
    }
    cout << "rank" << endl;
    for (int i = 0; i < n; i++) {
        cout << "排名:" << rank[i] << " 后缀 " << i << " ";
        suf(s, i);
    }
    cout << "height" << endl;
    for (int i = 1; i < n; i++) {
        cout << "后缀" << sa[i - 1] << "与" << sa[i] << " lcp:" << height[i]
             << endl;
    }

    cout << "lcp for suffix 0" << endl;
    auto lcp = SA.getLcp(0);
    for (int i = 0; i < n; i++) {
        cout << "后缀:" << i << " lcp:" << lcp[i] << endl;
    }
    cout << "lcp for suffix 3" << endl;
    lcp = SA.getLcp(3);
    for (int i = 0; i < n; i++) {
        cout << "后缀:" << i << " lcp:" << lcp[i] << endl;
    }
    cout << "lcp for suffix 2" << endl;
    lcp = SA.getLcp(2);
    for (int i = 0; i < n; i++) {
        cout << "后缀:" << i << " lcp:" << lcp[i] << endl;
    }
    return 0;
}
/*
sa
排名:0 后缀:3 [1,1,1,1,2]
排名:1 后缀:4 [1,1,1,2]
排名:2 后缀:5 [1,1,2]
排名:3 后缀:0 [1,1,2,1,1,1,1,2]
排名:4 后缀:6 [1,2]
排名:5 后缀:1 [1,2,1,1,1,1,2]
排名:6 后缀:7 [2]
排名:7 后缀:2 [2,1,1,1,1,2]
rank
排名:3 后缀 0 [1,1,2,1,1,1,1,2]
排名:5 后缀 1 [1,2,1,1,1,1,2]
排名:7 后缀 2 [2,1,1,1,1,2]
排名:0 后缀 3 [1,1,1,1,2]
排名:1 后缀 4 [1,1,1,2]
排名:2 后缀 5 [1,1,2]
排名:4 后缀 6 [1,2]
排名:6 后缀 7 [2]
height
后缀3与4 lcp:3
后缀4与5 lcp:2
后缀5与0 lcp:3
后缀0与6 lcp:1
后缀6与1 lcp:2
后缀1与7 lcp:0
后缀7与2 lcp:1
lcp for suffix 0
后缀:0 lcp:8
后缀:1 lcp:1
后缀:2 lcp:0
后缀:3 lcp:2
后缀:4 lcp:2
后缀:5 lcp:3
后缀:6 lcp:1
后缀:7 lcp:0
lcp for suffix 3
后缀:0 lcp:2
后缀:1 lcp:1
后缀:2 lcp:0
后缀:3 lcp:8
后缀:4 lcp:3
后缀:5 lcp:2
后缀:6 lcp:1
后缀:7 lcp:0
lcp for suffix 2
后缀:0 lcp:0
后缀:1 lcp:0
后缀:2 lcp:8
后缀:3 lcp:0
后缀:4 lcp:0
后缀:5 lcp:0
后缀:6 lcp:0
后缀:7 lcp:1
*/