from sys import stdin
from heapq import *
from sys import setrecursionlimit

setrecursionlimit(10000)

class edge:
    def __init__(self,to,lon,cost):
        self.to  = to
        self.lon = lon
        self.cost = cost
        
    def __lt__(self, other):
        if (self.lon == other.lon):
            return self.cost > other.cost
        return self.lon > other.lon

def isBest(oldEdge , newEdge):
    if (newEdge < oldEdge):
        return -1;
    if (oldEdge <newEdge):
        return 1;
    return 0

global inf
inf = 1e12

def dijkstra(graph,n):
    best = [ edge(i,inf,inf) for i in range(n+1)]
    best[1] = edge(1,0,0)
    pq = [ edge(1,0,0) ]
    while pq:
        u = heappop(pq)
        if(isBest(u,best[u.to])==1):
            continue
        for v in graph[u.to]:
            nw = edge(v.to, u.lon + v.lon, v.cost)
            if(isBest(nw,best[v.to]) == -1):
                best[v.to]= nw;
                heappush(pq,nw)
    ans = 0
    for i in range(1,n+1):
        ans+=best[i].cost       
    return ans

def main():
    n , m = [int(x) for x in stdin.readline().strip().split()]  
    graph = [ [] for i in range(n+1)]
    for i in range(m):
        u , v , lon, cost = [int(x) for x in stdin.readline().strip().split()]  
        graph[u].append(edge(v,lon,cost));
        graph[v].append(edge(u,lon,cost)); 
    print(dijkstra(graph,n))
main()

