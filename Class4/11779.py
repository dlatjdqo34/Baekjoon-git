import sys
import heapq
input = sys.stdin.readline

N = int(input())
M = int(input())
MAX_COST = 200000000

graph = [{} for _ in range(N+1)]
costs = [MAX_COST] * (N+1)
visited = [False] * (N+1)

for _ in range(M):
    start, dest, cost = map(int, input().split())
    if dest in graph[start]:
        graph[start][dest] = min(cost, graph[start][dest])
    else:
        graph[start][dest] = cost

start, dest = map(int, input().split())

def Dijk(cur):
    path = {i:cur for i in range(1,N+1)}
    heap = [(0, start)]
    costs[start] = 0
    heapq.heapify(heap)
    
    while len(heap):
        cost, cur = heapq.heappop(heap)
        if visited[cur]: 
            continue
        visited[cur] = True
        
        if cur == dest:
            print(costs[dest])
            count = 0
            temp = []
            while cur != start:
                count += 1
                temp.append(cur)
                cur = path[cur]
            temp.append(start)
            print(count + 1)
            print(" ".join(list(map(str, list(reversed(temp))))))
            break
        
        for nx, nx_cost in graph[cur].items():
            if not visited[nx] and costs[nx] > nx_cost + cost:
                path[nx] = cur
                costs[nx] = nx_cost + cost
                heapq.heappush(heap, (costs[nx], nx))


Dijk(start)