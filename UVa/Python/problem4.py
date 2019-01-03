from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(9000000)

def union(u,v):
    global padres,rank
    xR = find(u)
    yR = find(v)
    if rank[xR] < rank[yR]:
        padres[yR] = xR
    else:
        padres[xR] = yR
        if rank[xR]==rank[yR]:
            rank[yR]+=1

def find(x):
    global padres,rank
    if padres[x]!=x:
        padres[x] = find(padres[x])
    return padres[x]

def foundBCC(lo):
    global bccCont,st
    lon = len(st)
    if lon==0:return
    st = st[:lo]
    bccCont+=1

def tarjan(u):
    global g,grSCC,SCC,vis,dfsCont,num,low,dfsParent,dfsChild,articulation,bridge,p,bccCont   
    num[u]  = low[u] = dfsCont
    dfsCont+=1
    vis[u] = 1
    for v in g[u]:
        if not vis[v]:
            st.append((u,v))
            if( u == dfsParent):
                dfsChild+=1
            p[v] = u
            tarjan(v)
            if(low[v]>=num[u]):
                articulation[u]  = True
                if(low[v]>num[u]):
                    bridge.append((u,v))
                for lo in range(len(st)-1,-1,-1):
                    if st[lo] ==(u,v):
                        foundBCC(lo)
                        break
            low[u] = min(low[u],low[v])
        elif(v != p[u]):
            low[u] = min(low[u],num[v])
def main():
    global g,grSCC,SCC,vis,dfsCont,num,low,dfsParent,dfsChild,articulation,bridge,p,st,bccCont
    global padres,rank
    ntc = int(stdin.readline().strip())
    for casos in range(1,ntc+1):
        print("Caso {}:".format(casos))
        st = stdin.readline().strip()
        n , e = [int(x) for x in stdin.readline().strip().split()]
        g = [[] for x in range(n+1)]
        vis = [ 0  for x in range(n+1)]
        p = [ x  for x in range(n+1)]
        bridge = list()
        articulation = [ False  for x in range(n+1)]
        num = [ -1 for x in range(n+1)]
        low = [ -1 for x in range(n+1)]
        padres =[ x  for x in range(n+1)]
        rank = [ 0  for x in range(n+1)]
        st= list()
        componentes = n 
        for edge in range(e):
            u , v = [int(x) for x in stdin.readline().strip().split()]
            g[u].append(v)
            g[v].append(u)
            if(find(u)!=find(v)):
                union(u,v)
                componentes-=1
        print("Cantidad de componentes conexos:",componentes)
        bccCont = 1  
        dfsCont = 0
        for i in range(n):
            if not vis[i]:
                dfsParent = i
                dfsChild = 0
                tarjan(i)
                articulation[i] = (dfsChild>1)
                foundBCC(0)
        defAr = list()
        for i in range(n):
            if articulation[i]  :
                defAr.append(i)
        bridge.sort()
        print("Cantidad de componentes biconectados:",bccCont)
        print("Vértices de corte:",defAr)
        print("Arcos de corte:",bridge)
        #print(grSCC)
main()
