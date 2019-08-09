
from matplotlib import pyplot as plt
from networkx import nx
from collections import deque
import random

random.seed('Second spaning tree...')

class GenInput:

    def __init__(self, n : int ):
        self.n = n
        self.graph_cycle()

    def triangle_tree(self):
        f= open("test.in","w+")
        f.write("{} {}\n".format(self.n,self.n-1+self.n//2 -2))
        h = 10#random.randrange(1,10)
        G = [[] for i in range(2*self.n+10)]
        W = [[] for i in range(4*self.n+10)]
        for i in range(1,self.n//2):
            G[i].append(i+1)
            W[i].append(1)
            print(i,i+1)
            f.write("{} {} 1\n".format(i,i+1))
        nodeCurrent = 1
        for i in range(self.n//2+1,self.n+1):
            print(nodeCurrent,i)
            G[nodeCurrent].append(i)
            W[nodeCurrent].append(1)            
            f.write("{} {} 1\n".format(nodeCurrent,i))
            nodeCurrent = i
        que = []
        for i in range(2,self.n//2):
            G[i].append(self.n//2+i-1)
            W[i].append(10)            
            f.write("{} {} 10\n".format(i,self.n//2+i-1))
            que.append([i,self.n//2+i-1])
        f.write("{}\n".format(len(que)))
        for u,v in que:
            f.write("{} {}\n".format(u,v))
        f.close()
        
        self.showGraph(G,W)

    def binary_tree(self):
        f= open("test.in","w+")
        f.write("{} {}".format(self.n,self.n-1))
        h = 10#random.randrange(1,10)
        G = [[] for i in range(4*self.n+10)]
        W = [[] for i in range(4*self.n+10)]
        q = deque()
        q.append((1,1))
        mst = 0
        while q:
            tup  = q.popleft()
            if tup[1]>h or tup[0]>4*self.n:
                continue
            current = tup[0]
            w = random.randrange(9000,10000)
            G[current].append(current*2)
            G[current].append(current*2+1)
            W[current].append(w)
            mst+=w
            W[current].append(w)
            mst+=w
            f.write("{} {} {}\n".format(current,current*2,w))
            f.write("{} {} {}\n".format(current,current*2+1,w))
            q.append((current*2,tup[1]+1))
            q.append((current*2+1,tup[1]+1))
        f.write("2")
        f.write("1 2")
        f.close()
        
    
    def graph_cycle(self):
        f= open("test.in","w+")
        f.write("{} {}".format(self.n,self.n-1))
        G = [[] for i in range(2*self.n+10)]
        W = [[] for i in range(2*self.n+10)]
        m = 0
        for i in range(1,self.n+1):
            for j in range(i+1,self.n+1):
               m+=1
        f.write("{} {}\n".format(self.n,m))
        
        for i in range(1,self.n+1):
            for j in range(i+1,self.n+1):
                f.write("{} {} {}\n".format(i,j , 1 if i+1==j else 10))
                G[i].append(j)
                W[i].append(1 if i+1==j else 10)
        query = 0
        for i in range(1,self.n+1):
            for j in range(i+2,self.n+1):
                query+=1
        f.write("{}".format(query))        
        for i in range(1,self.n+1):
            for j in range(i+2,self.n+1):
                f.write("{} {}\n".format(i,j))
        f.close()    
        mst = self.n-1
        self.showGraph(G,W)

    
    def randomGraphW(self,directed=True):
        nxG = nx.gnm_random_graph(self.n,self.n-1,directed=directed,seed=random.getrandbits(20))
        #nxG = nx.balanced_tree(self.n,m)
        inp = ""
        out = ""
        mst = 0 
        q = 0
        G = [[] for i in range(self.n)]
        W = [[] for i in range(self.n)]
        for i,j in nxG.edges:
            w = random.randrange(9000,10000)
            G[i].append(j)
            inp += "{} {} {}".format(i+1,j+1,w)+'\n'
            mst+=w
            q+=1
            out +="{} {}".format(i+1,j+1)+'\n'
            W[i].append(w)
            if not directed:
                G[j].append(i)
                W[j].append(w)
        inp+="{}".format(q)+'\n'
        inp+=out
        print(inp)
        self.showGraph(G,W)

    def showGraph(self,G, W=None):
        n = len(G)
        E = [(i,j) for i in range(self.n) for j in G[i]]
        nxG = nx.Graph(E)
        pos = nx.spring_layout(nxG)
        nx.draw(nxG,pos,with_labels=True,node_color='yellow',
               node_size=500)
        if W is not None:
            labels = [W[i][k] for i in range(n) for k in range(len(G[i]))]
            for (i,j),w in zip(E,labels):
                nxG[i][j]['weight'] = w
            labels = nx.get_edge_attributes(nxG,'weight')
            nx.draw_networkx_edge_labels(nxG, pos, edge_labels=labels)
        plt.show()
        return
