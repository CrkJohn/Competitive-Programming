from matplotlib import pyplot as plt
from networkx import nx
import random

random.seed('Second spaning tree...')

class GenInput:

    def __init__(self, n : int )
        self.n = n

    def create_tree_triangle():
        inp = f"{self.n} {self.n-1}"
        if self.n & 1:

        else:


        return inp


    def randomGraphW(n,directed=True):
        nxG = nx.gnm_random_graph(n,m,directed=directed,seed=random.getrandbits(20))
        inp = ""
        mst = 0 
        q = 0
        for i,j in nxG.edges:
            w = random.randrange(100,1000) 
            inp += "{} {} {}".format(i+1,j+1,w)
            mst+=w
            q+=1
            out +="{} {}".format(i+1,j+1)        
        inp+="{}".format(q)
        inpt+=out
        return inp,mst
