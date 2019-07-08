from sys import stdin
from collections import deque


class Graph:

    def __init__(self, vertices, is_undirected=True):
        self.__v = vertices  # number of vertices
        self.__is_undirected = is_undirected # True for undirected graphs
        self.__adj_list = [[] for i in range(self.__v)] 
        self.const = ord('a')
        
    # method for adding an edge to the graph
    def add_edge(self, U, V, w=None):
        u = ord(U) - self.const 
        v = ord(V)- self.const 
        self.__adj_list[u].append([v, w if w else 1])
        # in case it is an undirected graph, 
        # replicate edge in opposite way
        if self.__is_undirected:
            self.__adj_list[v].append([u, w if w else 1])


    def bfs(self,src,tgt):
        src = ord(src)-self.const 
        tgt = ord(tgt) - self.const
        visited = [False] * self.__v
        queue = deque()
        queue.append(src)
        while(len(queue)):
            u = queue.popleft()
            if(u == tgt):
             return True
            for v,w in self.__adj_list[u]:
                if not visited[v]:
                    queue.append(v);
                    visited[v] = 1;
        return False


def main():
    line = stdin.readline().strip()
    while line:        
        connections, queries = [int(x) for x in line.split()]
        graph = Graph(28,False)
        for addEges in range(connections):
            u  , v = stdin.readline().strip().split()
            graph.add_edge(u,v)
        for q in range(queries):
            source , target = stdin.readline().strip().split()
            ok = 1  if len(source) == len(target) else 0 
            for i in range(len(source)):
                ok &= graph.bfs(source[i],target[i]) 
            print("yes" if ok else "no")
        line = stdin.readline().strip().split()
        
main()  