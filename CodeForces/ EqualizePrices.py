from sys import stdin
from math import *


def main():

    q = int(stdin.readline())
    for query in range(q):
        n,k = [int(x) for x in stdin.readline().strip().split()]
        products = [int(x) for x in stdin.readline().strip().split()]
        res = int(1e9)
        maxi = max(products)
        mini = min(products)
        #print("aca",diferencia)
        res = set()
        for p in products:
            res.add(p+k)
            #print(p+k,end=" ")
        sol = True
        resultado = -1
        #print(res)
        for s in res:
            sol = True
            tmp = abs(products[0]-s)
         #   print("-> " , tmp , k ,s)
            if(tmp > k):
                continue
            for p in products[1::]:
                if  abs(p-s) > k:
                    sol = False
                    break        
            if sol == True:
                resultado = s
        print(resultado)
        
main()
