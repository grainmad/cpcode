## 题目

[6. Z 字形变换](https://leetcode.cn/problems/zigzag-conversion/)


---


将一个给定字符串 `s` 根据给定的行数 `numRows` ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 `"PAYPALISHIRING"` 行数为 `3` 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：`"PAHNAPLSIIGYIR"`。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

 

**示例 1：**

**输入：**s = "PAYPALISHIRING", numRows = 3
**输出：**"PAHNAPLSIIGYIR"

**示例 2：**

**输入：**s = "PAYPALISHIRING", numRows = 4
**输出：**"PINALSIGYAHRPI"
**解释：**
P     I    N
A   L S  I G
Y A   H R
P     I

**示例 3：**

**输入：**s = "A", numRows = 1
**输出：**"A"

 

**提示：**

	- `1 <= s.length <= 1000`

	- `s` 由英文字母（小写和大写）、`','` 和 `'.'` 组成

	- `1 <= numRows <= 1000`


## 题解


### 思路

todo


### 代码


```cpp
// 执行用时: 304 ms
// 内存消耗: 125.7 MB
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        vector <string> gf(numRows, string (s.size(), ' '));
        int flag = 0;
        for (int i=0, x=0, y=0; i<s.size(); i++) {
            gf[x][y] = s[i];
            if (i%(numRows-1) == 0)flag = 1 - flag;
            if (flag) {
                x++;
            }else {
                x--,y++;
            }
        }
        string str;
        for (int i=0; i<numRows; i++) {
            for (int j=0; j<s.size(); j++) {
                if (gf[i][j] != ' ') 
                   str = str + gf[i][j]; 
            }
        }
        return str;
    }
};
// 执行用时: 148 ms
// 内存消耗: 94.7 MB
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        string str;
        int row = 2 * (numRows - 1);
        int intervals;
        int temp;
        for (int i=0; i<numRows; i++) {
            intervals = 2*i;
            temp = i;
            str = str + s[i];
            while (temp < s.size()) {
                intervals = row - intervals;
                temp += intervals;
                if (intervals == 0 || temp >= s.size())
                    continue;
                str = str + s[temp];
            }
        }
        return str;
    }
};
// 执行用时: 0 ms
// 内存消耗: 8 MB

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        if (numRows == 2) {
            string rt;
            for (int i=0; i<s.size(); i+=2) rt.push_back(s[i]);
            for (int i=1; i<s.size(); i+=2) rt.push_back(s[i]);
            return rt;
        }
        string rt;
        for (int i=0; i<s.size(); i+=(numRows-1)*2) rt.push_back(s[i]);
        for (int c=1; c<numRows-1; c++) {
            for (int i=c, j=0; i<s.size(); i+=(j%2?2*c:(numRows-c-1)*2), j++) rt.push_back(s[i]);
        }
        for (int i=numRows-1; i<s.size(); i+=(numRows-1)*2) rt.push_back(s[i]);
        return rt;
    }
};
```
