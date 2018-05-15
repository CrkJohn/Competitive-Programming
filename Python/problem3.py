from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(9000000)

def kosaraju(u,typ):
    global g,gR,st,grSCC,SCC,vis
    adj =  g[u] if(typ == 1) else gR[u]
    vis[u] = 1
    for v in adj:
        if not vis[v]:
            kosaraju(v,typ)
    if(typ==1):
        st.append(u)
    else:
        grSCC[u] = SCC


def tarjan(u):
    global g,grSCC,SCC,vis,num,low,dfsCont
    num[u]  = low[u] = dfsCont
    dfsCont+=1
    vis[u] = 1
    st.append(u)
    for v in g[u]:
        if num[v]==-1:
            tarjan(v)
        if vis[v]:
            low[u] = min(low[u],low[v])
    print("Tarjan" ,u , low[u],num[u])
    if(num[u]==low[u]):
        while(1):
            v = st.pop()
            vis[v] = 0
            grSCC[v] = SCC
            #print("Ig",v)
            if(u==v):break;
        SCC+=1
        
    

def main():
    global g,gR,st,grSCC,SCC,vis,dfsCont,num,low
    ntc = int(stdin.readline().strip())
    for casos in range(1,ntc+1):
        print("Caso {}:".format(casos))
        st = stdin.readline().strip()
        n , e = [int(x) for x in stdin.readline().strip().split()]
        g = [[] for x in range(n+1)]
        vis = [ 0  for x in range(n+1)]
        num = [ -1 for x in range(n+1)]
        low = [ -1 for x in range(n+1)]
        grSCC = [ 0 for x in range(n+1)]
        gR = [[] for x in range(n+1)]
        for edge in range(e):
            u , v = [int(x) for x in stdin.readline().strip().split()]
            g[u].append(v)
            gR[v].append(u)
        SCC = 0
        dfsCont = 0
        st  = list()
        for i in range(n):
            #print(i)
            if not(vis[i]):
                #num[u]  = low[u] = dfsCont
                kosaraju(i,1)
        rev = st[::-1]
        vis = [ 0  for x in range(n+1)]
        for i in rev:
            if not(vis[i]):
                kosaraju(i,2)
                SCC+=1
            
        #print(SCC)
        print("Cantidad de componentes fuertemente conectados: {}".format(SCC))

        gSCC = [[] for x in range(SCC)]
        inDegree = [ 0 for x in range(SCC)]
        listaDeArcosSCC = list()
        for no in range(n):
            lon = len(g[no])
            for u in range(lon):
                v = g[no][u]
                if(grSCC[no]!=grSCC[v]):
                    gSCC[grSCC[no]].append(grSCC[v])
                    inDegree[grSCC[v]]+=1
                    listaDeArcosSCC.append((no,v))
        c = 0
        for ing in inDegree:
            if not(ing):
                c+=1
        listaDeArcosSCC.sort()
        print("Cantidad de componentes fuertemente conectados con in-degree 0: {}".format(c))
        print("Arcos que conectan componentes fuertemente conectados:",listaDeArcosSCC)       
        #print(grSCC)
main()


