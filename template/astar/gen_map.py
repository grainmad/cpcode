
from random import shuffle

n, m, b = 20, 40, 0

x = ['.' for i in range(n*m)]

x[0] = 'S'
x[1] = 'E'
for i in range(2, b+2):
    x[i] = '#'

shuffle(x)
with open("./template/astar/map.txt", "w") as f:
    print(n, m, b, file=f)
    for i in range(n):
        for j in range(m):
            print(x[i*m+j], end='', file=f)
        print(file=f)
