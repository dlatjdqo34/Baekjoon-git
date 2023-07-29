import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

MAX_COST = 200000000
N = int(input())
M = int(input())

graph = [{} for i in range(N+1)]
arr = [MAX_COST for i in range(N+1)]
visited = [False for i in range(N+1)]

for i in range(M):
    start, dest, cost = map(int, input().split())
    graph[start][dest] = cost
    # graph[dest].append((start, cost))

start, dest = map(int, input().split())

# O(N)
def pick_next_node():
    min_node = MAX_COST
    next_node = 0
    for i in range(1, N+1):
        if not visited[i] and min_node > arr[i]:
            min_node = arr[i]
            next_node = i
    return next_node

def dijk(cur):
    visited[cur] = True
    for next, cost in graph[cur].items():
        if visited[next]: continue
        arr[next] = min(arr[next], cost + arr[cur])
    next = pick_next_node()
    if next != 0:
        dijk(next)

print(f"graph: {graph}")

arr[start] = 0
dijk(start)

print(arr[dest])
print(f"arr: {arr}")