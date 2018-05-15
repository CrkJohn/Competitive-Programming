from sys import stdin
from heapq import *


def dijsktra(src,tgt):
    global g,n
    dis = [ int(1e9) for x in range(n+1)]
    vis = [ False for x in range(n+1)]
    pq = [(0,src)]
    while pq:
        w , u = heappop(pq)
        for wv , v in g[u]:
            if wv + w < dis[v]:
                dis[v] = (wv + w)
                heappush(pq,(dis[v],v))
    return dis[tgt]


def main():
    global g,n
    ntc = int(stdin.readline().strip())
    for casos in range(1,ntc+1):
        n , e , src, tgt = [int(x) for x in stdin.readline().strip().split()]
        g = [[] for x in range(n+1)]
        flang = 0
        for edge in range(e):
            u , v , w = [int(x) for x in stdin.readline().strip().split()]
            #$if(w<0):continue
            g[u].append((w,v))
            #g[v].append((w,u))
            flang  = 1
        res = 0
        if (src == tgt):
            print ("Caso {}: {}".format(casos,res))
        elif not (flang):
             print ("Caso {}: None".format(casos))
        else:
            r = dijsktra(src,tgt)
            if (r!=1e9):
                print ("Caso {}: {}".format(casos,r))
            else:
                print ("Caso {}: None".format(casos))
main()
