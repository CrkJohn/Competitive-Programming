from sys import stdin
from sys import setrecursionlimit


class Edge:

    """
    A class used to represent an edge between  u - > v with weight
    :param u: present a node with label u
    :type u: int
    :param v: present a node with label v
    :type v: int
    :param w: A flag used to print the columns to the console
        (default is False)
    :type w: int
    :returns: a edge
    :rtype: Node
    """ 
    def __init__(self,u : int ,v : int,w : int = 0):
        """            
        :param u: present a node with label u
        :type u: int
        :param v: present a node with label v
        :type v: int
        :param w: A flag used to print the columns to the console
            (default is False)
        :type w: int
        :returns: a edge
        :rtype: Node
        """        
        self.u = u
        self.v = v
        self.w = w

    def __str__(self)-> str:
        """
        :returns: a string that represent the edge between (u,v,w), u,v are nodes and w is the weigth the edge
        :rtype: str 
        """         
        return "Edge u({}) - w({})->  v:({}) ".format(self.u,self.v,self.w)     
    

class DisjoinSet:
    """
        A class used to represent an disjoin set the a graph
        :param n: represent the amount of nodes on the graph
        :type u: int
        :returns: a disjoin set
        :rtype: DisjoinSet
    """
    
    def __init__(self, n : int):
        """            
        :param n: represent the amount of nodes on the graph
        :type u: int
        :returns: a disjoin set
        :rtype: DisjoinSet
        """   
        self.padre = [x for x in range(n)]
        self.rank = [0 for x in range(n)]


    def Buscar(self, x : int) -> int:
        """            
        :param x: represent the label of  the node that search its father
        :type x: int
        :returns: x's father
        :rtype: int
        """ 
        if(self.padre[x]!=x):
            self.padre[x]=self.Buscar(self.padre[x])
        return self.padre[x]

    def Union(self, x : int , y : int):
        """            
        :param x: represents the label of the node that may be attached to the tree of the node y
        :type x: int
        :param y: represents the label of the node that may be attached to the tree of the node x
        :type y: int        
        """ 
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
    """
        A class used to represent an target with weigth 
        :param to: represent the label the node
        :type to: int
        :param w: represent the weigth of u -> v
        :type w: int
    """
    def __init__(self,to : int ,w : int):
        """
        :param to: represent the label the node
        :type to: int
        :param w: represent the weigth of u -> v
        :type w: int
        """
        self.to = to
        self.w = w
    def __str__(self) -> str:
        """
        :returns: a string that represent the target and weigth the a node i-th
        :rtype: str 
        """     
        return "({},{})".format(self.to,self.w)



def kruskal(n : int, unionFind :  DisjoinSet , listEdges = list()):
    """
    Create a minimun spaning tree given a list edges and at the same time creta the value itself
    :param n: represent the amount nodes in the graph
    :type n: int
    :param unionFind: represent the disjoin set of the nodes
    :type unionFind:  DisjoinSet
    :param listEdges: represent the list edge 
    :type listEdges: list of Edge 
    :returns: a int that represent the cost the minimun spaning tree  and a matriz in wich  the i-th position means  the list of node adyance the i-th node
    :rtype: int, list of list of type Nodes
    """     
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

def dfs(src : int , u  : int ,tree : list()):
    """
    Searching the value maximun edge that share src-u 
    :param src: represent the source the search
    :type src: int
    :param u: represent the node currenty begin explored 
    :type u:  int
    :param tree: represent the list of list of nodes, represent the minimun spaning tree 
    :type listEdges: list of list of nodes
    """     
    global maxEdge
    for node in tree[u]: 
        if maxEdge[src][node.to] > 0:
            continue
        maxEdge[src][node.to] = max(maxEdge[src][u],node.w) 
        dfs(src,node.to,tree)

def solve(mst, tree , cost, N):
    """
    Make a dfs over all nodes the graph searching the value maximun edge that share u-v after this response the queries, for each query
    calcule the value the second minimun spanig tree in time O(1)
    :param mst: represent the value the minimun spaning tree
    :type mst: int
    :param tree: represent the list of list of nodes, represent the minimun spaning tree 
    :type listEdges: list of list of nodes
    :param cost: represent the cost of going the node u-v 
    :type cost: is dictonary with a pair of int represented the edge between u-v and value the cost  of going u-v
    """     
    global maxEdge,std,test
    maxEdge = [ [ 0 for i in range(N)] for j in range(N)]
    for nodes,listTree in enumerate(tree):
        if listTree:
            dfs(nodes,nodes,tree)
    Queries = int(test.readline().strip()) if std else int(input())
    if std:
        f= open("test.out","w+")
       
    for q in range(Queries):
        u,v = [int(x) for x in test.readline().strip().split()] if std else  map(int,input().split())
        if not std:
            print(mst - maxEdge[u][v] + cost[(u,v)])
        f.write(f"{mst - maxEdge[u][v] + cost[(u,v)]}\n")
    f.close()
        
def read_input():
    """
    Read input the exercise 
    :returns: return a value boolean that means true if there are  something to read of otherwise not
    :rtype boolean
    """     
    global N,M,std,test
    lec = test.readline().strip() if std else stdin.readline().strip()
    print(lec)
    if not len(lec):
        return 0,0
    N , M = map(int,lec.split())    
    return N+1,M
        
def create_graph():
    """ 
    Crete a list of edges and at the same time a dictonary in wich keep as key a pair of int where the tuple is the edge between u-v
    and dictonary's value is the cost doing of u - v 
    """
    global M ,std 
    listEdges = list()
    cost = dict()
    cost = dict()
    for i in range(M):
        U,V,W = [int(x) for x  in test.readline().strip().split()] if std else map(int,input().split())
        listEdges.append(Edge(U,V,W))
        cost[(U,V)] = W
    listEdges.sort(key = lambda edgeSort : edgeSort.w)
    return listEdges,cost
      

def main(readFile = False):
    global std,test,M
    std  = readFile
    if std:
        test = open("test.in",'r')
    while 1:
        N,M = read_input()
        if( N == 0 or  M ==0):
            break
        listEdges, cost  =  create_graph()
        unionFind = DisjoinSet(N)
        mst, tree = kruskal(N,unionFind, listEdges)
        solve(mst, tree , cost ,N)

