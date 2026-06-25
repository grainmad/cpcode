## 题目

[25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)


---


给你链表的头节点 `head` ，每 `k`* *个节点一组进行翻转，请你返回修改后的链表。

`k` 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 `k`* *的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

 

**示例 1：**

[]

**输入：**head = [1,2,3,4,5], k = 2
**输出：**[2,1,4,3,5]

**示例 2：**

[]

**输入：**head = [1,2,3,4,5], k = 3
**输出：**[3,2,1,4,5]

 

**提示：**

	- 链表中的节点数目为 `n`

	- `1 <= k <= n <= 5000`

	- `0 <= Node.val <= 1000`

 

**进阶：**你可以设计一个只用 `O(1)` 额外内存空间的算法解决此问题吗？


## 题解


### 思路

直接模拟，练基本功


### 代码


```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode root(0, head), *t = &root, *p, *q1, *q2, *q3;
        while (t) {
            p = nextK(t, k);
            if (p == nullptr) break;
            q1 = t->next;
            q2 = t->next->next;
            q3 = t->next->next->next;
            while (q1 != p) {
                q2->next = q1;
                q1 = q2;
                q2 = q3;
                q3 = q3?q3->next:nullptr;
            }
            q3 = t->next;
            q3->next = q2;
            t->next = q1;
            t = q3;
        }
        return root.next;
    }
    ListNode* nextK(ListNode* head, int k) {//存在则返回第k个
        while (k && head) {
            head = head->next;
            k--;
        }
        return head;
    }
};
```
