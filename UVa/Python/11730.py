from sys import stdin
from collections import deque

global primes
primes = list();

def sieve(bound):
    Bound=bound+1;
    notp = [False for x in range(1000)]
    notp[0]=False;
    notp[1]=False;
    for i in range(2,Bound+1):
        if not(notp[i]):
            j = i*i
            while (j<=Bound):
                notp[j]=True
                j+=i
            primes.append(i)

def bfs(src,tgt):
    q = deque()
    q.append(src)
    vis = [float('inf') for x in range(1100)]
    vis[src] = 0
    while q:
        v = q.popleft()
        if(v==tgt):
            return vis[tgt]
        for p in primes:
            if(p>(v//2)):break
            if(v%p==0 and v+p<=tgt and vis[v+p]==float('inf')):
                vis[v+p] = vis[v] + 1
                q.append(p+v)
    return -1

            

def main():
    sieve(700)
    ntc = 1
    while True:
        src , tgt = [int(x) for x in stdin.readline().strip().split()]
        if(src+tgt==0):break
        print("Case {}: {}".format(ntc,bfs(src,tgt)))
        ntc+=1
main()
