# https://www.acmicpc.net/problem/1987
import sys

# input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

def DFS(x, y, count):
    global ans
    myset.add(maps[x][y])
    ans = max(ans, count)
    
    for dx, dy in directions:
        x1 = x + dx
        y1 = y + dy
        if x1 < 0 or x1 >= r or y1 < 0 or y1 >= c: 
            continue
        if maps[x1][y1] not in myset:
            DFS(x1, y1, count + 1) 
            myset.remove(maps[x1][y1])

r, c = map(int, input().split(" "))
ans = 0
myset = set()
directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
maps = [list(input().strip()) for _ in range(r)]

DFS(0, 0, 1)
print(ans)