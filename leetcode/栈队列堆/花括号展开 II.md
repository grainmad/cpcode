## 题目

[1096. 花括号展开 II](https://leetcode.cn/problems/brace-expansion-ii/)

---

如果你熟悉 Shell 编程，那么一定了解过花括号展开，它可以用来生成任意字符串。

花括号展开的表达式可以看作一个由 **花括号**、**逗号** 和 **小写英文字母** 组成的字符串，定义下面几条语法规则：

-   如果只给出单一的元素 `x`，那么表达式表示的字符串就只有 `"x"`。`R(x) = {x}`
    -   例如，表达式 `"a"` 表示字符串 `"a"`。
    -   而表达式 `"w"` 就表示字符串 `"w"`。
-   当两个或多个表达式并列，以逗号分隔，我们取这些表达式中元素的并集。`R({e_1,e_2,...}) = R(e_1) ∪ R(e_2) ∪ ...`
    -   例如，表达式 `"{a,b,c}"` 表示字符串 `"a","b","c"`。
    -   而表达式 `"{{a,b},{b,c}}"` 也可以表示字符串 `"a","b","c"`。
-   要是两个或多个表达式相接，中间没有隔开时，我们从这些表达式中各取一个元素依次连接形成字符串。`R(e_1 + e_2) = {a + b for (a, b) in R(e_1) × R(e_2)}`
    -   例如，表达式 `"{a,b}{c,d}"` 表示字符串 `"ac","ad","bc","bd"`。
-   表达式之间允许嵌套，单一元素与表达式的连接也是允许的。
    -   例如，表达式 `"a{b,c,d}"` 表示字符串 `"ab","ac","ad"​​​​​​`。
    -   例如，表达式 `"a{b,c}{d,e}f{g,h}"` 可以表示字符串 `"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"`。

给出表示基于给定语法规则的表达式 `expression`，返回它所表示的所有字符串组成的有序列表。

假如你希望以「集合」的概念了解此题，也可以通过点击 “**显示英文描述**” 获取详情。

  

**示例 1：**

```txt
输入：expression = "{a,b}{c,{d,e}}"
输出：["ac","ad","ae","bc","bd","be"]
```

**示例 2：**

```txt
输入：expression = "{{a,z},a{b,c},{ab,z}}"
输出：["a","ab","ac","z"]
解释：输出中 不应 出现重复的组合结果。
```
  

**提示：**

-   `1 <= expression.length <= 60`
-   `expression[i]` 由 `'{'`，`'}'`，`','` 或小写英文字母组成
-   给出的表达式 `expression` 用以表示一组基于题目描述中语法构造的字符串

  

## 解题

### 方法一：

#### 思路

这个问题类似求带括号的表达式。

我们可以将表达式转化为逆波兰式（后缀表达式）

对于逆波兰式没有括号，只需要一个栈就可以将表达式的值计算出来。

计算逆波兰式的算法过程：
遍历逆波兰式的符号，当前符号为字符串集合则加入栈中。
若当前元素为运算符则将栈顶两个字符串集合进行运算再放回栈中。这里运算有两种集合的并和笛卡尔积。
最后栈顶元素就是计算结果。

如何生成逆波兰式，我们需要对运算符设置优先级，维护一个运算符优先级单调增栈，对违背单调的待入栈元素将栈顶不断弹出放入逆波兰式中。
并运算优先级小于笛卡尔积运算优先级。
对于括号若为左括号则直接放入栈中。对于右括号不断弹栈知道遇到左括号为止。
对于非运算符则直接加入到逆波兰式中。


#### 代码

```cpp
class Solution {
public:
    /*
    { 1
    } 2
    , 3
    * 4
    */
    int mp[200];
    vector<string> braceExpansionII(string exp) {
        string s(1, exp[0]);
        for (int i=1; i<exp.size(); i++) {
            if (islower(exp[i-1]) && islower(exp[i])
            || islower(exp[i-1]) && exp[i] == '{'
            || exp[i-1] == '}' && islower(exp[i])
            || exp[i-1] == '}' && exp[i] == '{') {
                s.push_back('*');
            }
            s.push_back(exp[i]);
        }
        // cout << s << endl;
        mp['{'] = '1'; mp['}'] = '2';
        mp[','] = '3'; mp['*'] = '4';
        vector<set<string>> elm;
        string opt;
        for (char i:s) {
            if (mp[i] == '1') {
                opt.push_back(mp[i]);
            } else if (mp[i]) { // opt
                while (opt.size() && opt.back()>mp[i]) {
                    elm.push_back({string(1, opt.back())});
                    opt.pop_back();
                }
                if (mp[i] == '2') {
                    opt.pop_back();
                } else {
                    opt.push_back(mp[i]);
                }
            } else {
                elm.push_back({string(1, i)});
            }
        }
        while (opt.size()) {
            elm.push_back({string(1, opt.back())});
            opt.pop_back();
        }
        // for (auto i:elm) {
        //     for (string j:i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        vector<set<string>> st;
        for (int i=0; i<elm.size(); i++) {
            if (*elm[i].begin() == "3") {
                int sz = st.size();
                int l = sz-2, r = sz-1;
                for (auto x:st[r]) st[l].insert(x);
                st.pop_back();
            } else if (*elm[i].begin() == "4") {
                set<string> t;
                int sz = st.size();
                int l = sz-2, r = sz-1;
                for (auto x:st[l]) {
                    for (auto y:st[r]) {
                        t.insert(x+y);
                    }
                }
                st.pop_back();
                st.back() = t;
            } else {
                st.emplace_back(elm[i]);
            }

        }
        return vector<string>(st.back().begin(), st.back().end());
    }
};
```
