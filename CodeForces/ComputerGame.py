from sys import stdin
from math import *


def main():
    q = int(stdin.readline())
    for query in range(q):
        k,n,a,b = [int(x) for x in stdin.readline().strip().split()]
        k-=n*a
        if(k>0):
            print(n)
        else:
            k = -k
            k+=1
            diff  = a-b
            turns = (k+diff-1)//diff
            if(turns>n):
                print(-1)
            else:
                print(n-turns)
main()
