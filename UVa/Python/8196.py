from sys import stdin
from sys import setrecursionlimit


class Edge:
    def __init__(self,u,v,w):
        self.u = u
        self.v = v
        self.w = w
    def __str__(self):
        return "Edge u({}) - w({})->  v:({}) ".format(self.u,self.v,self.w)     
    

class DisjoinSet:
    def __init__(self, n):
        self.padre = [x for x in range(n)]
        self.rank = [0 for x in range(n)]

    def Buscar(self, x):
        if(self.padre[x]!=x):
            self.padre[x]=self.Buscar(self.padre[x])
        return self.padre[x]

    def Union(self, x, y):
        xRaiz = self.Buscar(x)
        yRaiz = self.Buscar(y)
        if(xRaiz == yRaiz):
            return
        if self.rank[xRaiz] < self.rank[yRaiz]:
            self.padre[xRaiz] = yRaiz
        elif self.rank[xRaiz] > self.rank[yRaiz]:
            self.padre[yRaiz] = xRaiz
        else:
            self.padre[yRaiz] = xRaiz
            self.rank[xRaiz]+=1

class Node:
    def __init__(self,to,w):
        self.to = to
        self.w = w
    def __str__(self):
        return "({},{})".format(self.to,self.w)



def kruskal(n, unionFind , listEdges = list()):
    mst = 0
    tree = [ [] for x in range(n)]
    for edgeIter in listEdges:
        e = edgeIter
        if unionFind.Buscar(e.u) != unionFind.Buscar(e.v):
            unionFind.Union(e.u,e.v)
            tree[e.u].append(Node(e.v,e.w))
            tree[e.v].append(Node(e.u,e.w))
            mst += e.w
    return mst,tree

def dfs(src, u ,tree):
  global maxEdge
  for node in tree[u]: 
    if maxEdge[src][node.to] > 0:
        continue
    maxEdge[src][node.to] = max(maxEdge[src][u],node.w) 
    dfs(src,node.to,tree)

if __name__ == "__main__":
    #lec = input().strip()
    while 1:
        lec = stdin.readline().strip()
        if len(lec) == 0:
            break
        #N , M = map(int,lec.split())    
        N, M = [int(x) for x in lec.split()]
        N+=1
        listEdges = list()
        cost = dict()
        for i in range(M):
            #U,V,W = map(int,input().split())
            U ,V ,W = [int(x) for x in stdin.readline().strip().split()]
            listEdges.append(Edge(U,V,W))
            cost[(U,V)] = W
        listEdges.sort(key = lambda edgeSort : edgeSort.w)
        unionFind = DisjoinSet(N)
        mst, tree = kruskal(N,unionFind, listEdges)
        """
        SECOND BEST SPANNING TREE IN O(ELOGV)
        INSTEAD OF O(EV)
        STEPS:
        1)Run Kruskal's Algorithm as normal, saving the edges as Adjacency List (AL) and 
        saving the edges not included in the MST in another Adjacency List (OTHER)
        2)Precalculate masEdge[i][j]='largest edge cost along the path i-j in AL
        3)For each edge (u-v) in OTHER, minimize: cost of MST - mat[u][v] + cost of (u-v) in OTHER
        4)The minimum found in 3) is the cost of the second best ST
        

        for i,k in enumerate(tree):
            print("Connection node i : ",i  , end = " ")
            for t in k:
                print(t , end = " ")
            print()
        """

        global maxEdge
        maxEdge = [ [ 0 for i in range(N)] for j in range(N)]
        for nodes,listTree in enumerate(tree):
            if listTree:
                dfs(nodes,nodes,tree)

        #Queries = int(input())
        Queries = int(stdin.readline().strip())
        for q in range(Queries):
            u , v = [int(x) for x in stdin.readline().strip().split()]
            #u,v = map(int,input().split())
            print(mst - maxEdge[u][v] + cost[(u,v)])
    
    