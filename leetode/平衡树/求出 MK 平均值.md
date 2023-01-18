## 题目

[1825. 求出 MK 平均值](https://leetcode.cn/problems/finding-mk-average/)

---

给你两个整数 `m` 和 `k` ，以及数据流形式的若干整数。你需要实现一个数据结构，计算这个数据流的 **MK 平均值** 。

**MK 平均值** 按照如下步骤计算：

1.  如果数据流中的整数少于 `m` 个，**MK 平均值** 为 `-1` ，否则将数据流中最后 `m` 个元素拷贝到一个独立的容器中。
2.  从这个容器中删除最小的 `k` 个数和最大的 `k` 个数。
3.  计算剩余元素的平均值，并 **向下取整到最近的整数** 。

请你实现 `MKAverage` 类：

-   `MKAverage(int m, int k)` 用一个空的数据流和两个整数 `m` 和 `k` 初始化 **MKAverage** 对象。
-   `void addElement(int num)` 往数据流中插入一个新的元素 `num` 。
-   `int calculateMKAverage()` 对当前的数据流计算并返回 **MK 平均数** ，结果需 **向下取整到最近的整数** 。

  

**示例 1：**

```txt
输入：
["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement", "addElement", "addElement", "calculateMKAverage"]
[[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
输出：
[null, null, null, -1, null, 3, null, null, null, 5]

解释：
MKAverage obj = new MKAverage(3, 1); 
obj.addElement(3);        // 当前元素为 [3]
obj.addElement(1);        // 当前元素为 [3,1]
obj.calculateMKAverage(); // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
obj.addElement(10);       // 当前元素为 [3,1,10]
obj.calculateMKAverage(); // 最后 3 个元素为 [3,1,10]
                          // 删除最小以及最大的 1 个元素后，容器为 [3]
                          // [3] 的平均值等于 3/1 = 3 ，故返回 3
obj.addElement(5);        // 当前元素为 [3,1,10,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5,5]
obj.calculateMKAverage(); // 最后 3 个元素为 [5,5,5]
                          // 删除最小以及最大的 1 个元素后，容器为 [5]
                          // [5] 的平均值等于 5/1 = 5 ，故返回 5
```
  

**提示：**

-   `3 <= m <= 10^5`
-   `1 <= k*2 < m`
-   `1 <= num <= 10^5`
-   `addElement` 与 `calculateMKAverage` 总操作次数不超过 `10^5` 次。

  

## 解题

### 方法一：

#### 思路

我们将最后m个数分成三个可重集合：最小的k个数`l`，最大的k个数`r`，剩余的m-2k个数`c`。并用`sum`实时统计`c`中元素和。


类似滑动窗口，我们可以用一个队列来维护数据流中最后m个数。

在每次添加一个新元素`a`到队列中后：
* 当队列中元素不超过m个，无需操作，此时MK平均值就是-1。
* 当队列中元素恰好等于m个，我们就构造`l`，`r`，`c`三个集合。以及`c`中元素和`sum`，此时MK平均值就是`sum/(m-2*k)`
* 当队列中元素大于等于m个，我们需要删除队头元素`d`，且在三个集合中添加`a`，删除`d`，并调整三个集合。
    * 插入`a`。为了保证`l`是最后m个数中最小k个数，如果`l`中最大的数大于`a`，说明`a`成了最小的k个数之一，此时`l`中最大的数应该要移动到`c`中，移动后`c`中的数始终还是不大于`r`的，所以`r`无需调整；若尝试插入到`l`中失败，同理尝试插入到`r`中，此时的判断条件应该是`a`大于r的最小值；最后若插入`l`和`r`都失败了，就插入到`m`中。这个过程中注意更新`c`中元素和`sum`。执行插入操作后，使得了`c`中元素多了一个。
    * 删除`d`。若`l`中存在`d`，删除后导致了`l`少了一个元素，而`c`中恰多一个，为了维护`l`是最小的k个数，将`c`中最小值移动到`l`中；若`l`中不存在，则同理尝试在`r`中寻找并删除；若`l`和`r`中都不在，则一定在`c`中。实时更新`sum`。

我们对集合的操作有增加元素，删除元素，查找元素，查找最值。可以使用能高效的进行这些操作的数据结构——平衡树。

#### 代码

```cpp
class MKAverage {
public:
    queue<int> q;
    multiset<int> l, c, r;
    int m, k;
    long long sum;
    MKAverage(int m, int k):m(m),k(k),sum(0) {

    }
    void add(int x) {
        if (*l.rbegin()>x) {
            l.insert(x);
            c.insert(*l.rbegin());
            sum += *l.rbegin();
            l.erase(--l.end());
        } else if (*r.begin()<x) {
            r.insert(x);
            c.insert(*r.begin());
            sum += *r.begin();
            r.erase(r.begin());            
        } else {
            c.insert(x);
            sum += x;
        }
    }
    void del(int x) {
        if (l.count(x)) {
            l.erase(l.find(x));
            l.insert(*c.begin());
            sum -= *c.begin();
            c.erase(c.begin());
        } else if (r.count(x)) {
            r.erase(r.find(x));
            r.insert(*c.rbegin());
            sum -= *c.rbegin();
            c.erase(--c.end());
        } else {
            c.erase(c.find(x));
            sum -= x;
        }
    }
    void addElement(int num) {
        q.push(num);
        if (q.size() < m) return ;
        if (q.size() == m) {
            auto t = q;
            while (t.size()) c.insert(t.front()), t.pop();
            for (int i=0; i<k; i++) {
                l.insert(*c.begin());
                c.erase(c.begin());
                r.insert(*c.rbegin());
                c.erase(--c.end());
            }
            for (int i:c) sum += i;
            return ;
        }
        add(num);
        del(q.front());
        q.pop();
    }
    
    int calculateMKAverage() {
        if (q.size()<m) return -1;
        return sum/(m-2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
```
