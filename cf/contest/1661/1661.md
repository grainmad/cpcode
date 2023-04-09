# Educational Codeforces Round 126 (Rated for Div. 2)
# A
给出两个数组a和b
可以交换$a_i$与$b_i$，问$\sum \limits_{i=1}^{n-1} (|a_i-a_{i+1}|+|b_i-b){i+1}|)$的最小值是多少
遍历0到n-2，对于当前遍历的下标i, 若$|a_{i}-a_{i+1}|+|b_{i}-b_{i+1}|>|a_{i}-b_{i+1}|+|b_{i}-a_{i+1}|$ 则交换$a_{i+1}$与$b_{i+1}$

# B

# C
