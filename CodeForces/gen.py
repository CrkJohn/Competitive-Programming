"""
def criba_eratostenes(n):
  multiplos = set()
  for i in range(2, n+1):
    if i not in multiplos:
      print(i)
      multiplos.update(range(i*i, n+1, i))

criba_eratostenes(10000020)
"""

from matplotlib import pyplot as plt
from networkx import nx

import random
random.seed('Me gusta algo...')

def randomGraphW(n,m,directed=True):
    nxG = nx.gnm_random_graph(n,m,directed=directed,
                             seed=random.getrandbits(20))
    G = [[] for i in range(n)]
    W = [[] for i in range(n)]
    
    for i,j in nxG.edges:
        print(i+1,j+1 , end = " ")
        G[i].append(j)
        w = random.randrange(80231,893320068)
        c = random.randrange(1,100)
        print(w)
        W[i].append(w)
        if not directed:
            G[j].append(i)
            W[j].append(w)
    return G, W

def showGraph(G, W=None):
    n = len(G)
    E = [(i,j) for i in range(n) for j in G[i]]
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

n = 100000
m = 200000
print(n,m,400)
G,W = randomGraphW(n,m, directed=False)